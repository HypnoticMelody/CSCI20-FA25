#include <iostream>
#include <array>

struct Stack {
    int index = 0;
    size_t size = 5;
    std::array<int, 5> data = {}; // how do you make the size able to change on construction
    



    void push(int e) {
        index += 1;
        for (size_t i = 0; i < size; i++) {
            data[size - i] = data[size - i - 1];
        }
        data[0] = e;
    }

    int pop() {
        if (index >= 0) {
            index -= 1;
            int value = data[0];
            for (size_t i = 1; i < size; i++) {
                data[i - 1] = data[i];
            }
            data[size] = 0;
            return value;
        }
    }

    void print() {
        std::cout << "{";
        for (size_t i = 0; i < size; i++) {
            std::cout << data[i] << ", ";
        }
        std::cout << "}\n";
    }
};

int main() {
    Stack s; // stuck at array size 5 :(
    s.push(5);
    s.push(6);

    s.print();

    std::cout << s.pop() << "\n";
    std::cout << s.pop() << "\n";
    return 0;
}