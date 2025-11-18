#include "ezPrint.hpp"
#include <vector>

// Meet the stack struct! She can handle anything you put inside her~ ...wait, that's uh. Forget I said that.
template <typename T>
struct Stack {
    size_t size = 0;
    std::vector<T> data = {};

    void push(T e) {
        data.push_back(e);
        size = size + 1;
        std::cout << "Pushed on: " << e << "\n";
        return;
    }

    T pop() {
        size = size - 1;
        int value = data[size];
        data.pop_back();
        std::cout << "Popped off: " << value << "\n";
        return value;
    }

    void print() {
        ezPrint(data, false);
        std::cout << "\n";
        return;
    }
};