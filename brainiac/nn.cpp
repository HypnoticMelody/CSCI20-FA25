#include <iostream>
#include <vector>
#include <stdexcept>
#include <random>
#include <algorithm>

static std::mt19937 seed(13);
static std::uniform_int_distribution<> distrib(0, 32767);



double rand_num(double min, double max) {
    return (static_cast<double>(distrib(seed)) / 16383.5) - 1;
}

void vprint(std::vector<double> vec, bool newLine = true) {
    std::cout << "[";
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i];
        if (i != vec.size() - 1) {
            std::cout << " ";
        }
    }
    std::cout << "]";
    if (newLine) {
        std::cout << "\n";
    }
}

struct Matrix {
    std::vector<std::vector<double>> data;

    Matrix() = default;
    Matrix(size_t cols, size_t rows, double fill = 0.0) {
        data.assign(rows, std::vector<double>(cols, fill));
    }
    Matrix(std::vector<std::vector<double>> _data) : data(_data) {}

    size_t rcount() const { return data.size(); }
    size_t ccount() const { return data.empty() ? 0 : data[0].size(); }

    double& operator()(size_t x, size_t y) { return data.at(y).at(x); }
    const double& operator()(size_t x, size_t y) const { return data.at(y).at(x); }

    void print() const {
        std::cout << "[\n";
        for (size_t y = 0; y < rcount(); y++) {
            std::cout << "  [";
            for (size_t x = 0; x < ccount(); x++) {
                std::cout << data[y][x];
                if (x != ccount() - 1) std::cout << ", ";
            }
            std::cout << "]";
            if (y != rcount() - 1) std::cout << ",";
            std::cout << "\n";
        }
        std::cout << "]\n";
    }

    static Matrix identity(size_t n) {
        Matrix m(n, n, 0.0);
        for (size_t i = 0; i < n; i++) m(i, i) = 1.0;
        return m;
    }

    // matrix dot prod
    Matrix operator*(const Matrix& weights) const {
        if (ccount() != weights.ccount()) {
            throw std::invalid_argument("Matrix dimensions don't match for NN multiplication");
        }

        Matrix result(weights.rcount(), rcount(), 0.0);

        for (size_t x = 0; x < weights.rcount(); x++) {
            for (size_t y = 0; y < rcount(); y++) {
                double sum = 0.0;
                for (size_t i = 0; i < ccount(); i++) {
                    sum += (*this)(i, y) * weights(i, x);
                }
                
                result(x, y) = sum;
            }
        }
        return result;
    }

    // bias add
    Matrix operator+(const Matrix& bias) const {
        if (bias.ccount() != ccount()) {
            throw std::invalid_argument("Bias vector size must match number of columns");
        }
        Matrix result = *this;
        for (size_t y = 0; y < rcount(); y++) {
            for (size_t x = 0; x < ccount(); x++) {
                result(x, y) += bias(x, 0);
            }
        }
        return result;
    }
};

struct Layer_Dense {
    Matrix weights;
    Matrix biases;
    Matrix output;

    Layer_Dense(int inputCount, int neuronCount) : weights(inputCount, neuronCount), biases(neuronCount, 1) {
        for (size_t x = 0; x < inputCount; x++) {
            for (size_t y = 0; y < neuronCount; y++) {
                weights(x, y) = rand_num(-1.0, 1.0);
            }
        }
    }
    Matrix forward(Matrix inputs) {
        return output = inputs * weights + biases;
    }
    Matrix ReLU() {
        size_t X = output.ccount();
        size_t Y = output.rcount();
        Matrix newOutput(X, Y);
        for (size_t x = 0; x < X; x++) {
            for (size_t y = 0; y < Y; y++) {
                newOutput(x, y) = std::max(0.0, output(x, y));
            }
        }
        return newOutput;
    }
    void print() {
        output.print();
    }
};


// 4 -> 3 -> ?

int main() {
    Matrix inputs({ {0.0, 0.0},
                    {1.0, 1.0},
                    {2.0, 2.0},
                    {3.0, 3.0},
                    {4.0, 4.0},
                    {0.0, 0.0},
                    {1.0, -1.0},
                    {2.0, -2.0},
                    {3.0, -3.0},
                    {4.0, -4.0},});

    Layer_Dense layer1(2,5);

    layer1.forward(inputs);

    layer1.print();
    layer1.ReLU().print();
}