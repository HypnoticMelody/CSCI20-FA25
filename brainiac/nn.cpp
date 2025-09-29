#include <iostream>
#include <array>
#include <vector>



class neuron {
    private: // vars
        std::vector<double> inputs = {};

        std::vector<double> weights = {};
        double bias;
    public: // returning methods
        double out() {
            double output = bias;

            for (size_t i = 0; i < inputs.size(); i++) {
                output += inputs[i] * weights[i];
            }
            
            return output;
        }
    public: // void methods
        void set_inputs(std::vector<double> _inputs) {
            inputs = _inputs;
        }
        void set_weights(std::vector<double> _weights) {
            weights = _weights;
        }
        void set_bias(double _bias) {
            bias = _bias;
        }
};

std::vector<double> dot_prod(std::vector<std::vector<double>> _v1, std::vector<double> _v2) {
    std::vector<double> output = {};

    std::vector<double> __v1 = {};
    double subOutput = 0.0;

    for (size_t i = 0; i < _v1.size(); i++) {
        _v1i = _v1[i];
        subOutput = 0.0
        for (size_t j = 0; j < _v1i.size(); j++) {
            subOutput += _v1i[j] * _v2[i];
        }
        output.push_back(subOutput)
    }

    return output
}

// 4 -> 3 -> ?

int main() {
    std::vector<double> inputs = {1.0, 2.0, 3.0, 2.5};
    std::vector<std::vector<double>> weights = {{0.2, 0.8, -0.5, 1.0}, {0.5, -0.91, 0.26, -0.5}, {-0.26, -0.27, 0.17, 0.87}};
    std::vector<double> biases = {2, 3, 0.5}

    neuron n1;
    n1.set_inputs(inputs);
    n1.set_weights({0.2, 0.8, -0.5, 1.0});
    n1.set_bias(2.0);

    neuron n2;
    n2.set_inputs(inputs);
    n2.set_weights({0.5, -0.91, 0.26, -0.5});
    n2.set_bias(3.0);

    neuron n3;
    n3.set_inputs(inputs);
    n3.set_weights({-0.26, -0.27, 0.17, 0.87});
    n3.set_bias(0.5);

    std::cout << n1.out() << " " << std::cout << n2.out() << " " << n3.out();
}