#include <iostream>
#include <vector>

// IT'S EZPRINT TIME!!! WOOO!!! (it can handle any dimension vector, along with whatever type that can be normally printed by cout!)
template <typename T>
void ezPrint(T data) {
    std::cout << data;
}

template <typename T>
void ezPrint(std::vector<T> data, bool spacing = false) {
    std::cout << "{";
    if (spacing) { std::cout << "\n";}
    for (size_t i = 0; i < data.size(); i++) {
        ezPrint(data[i]);
        if (spacing) { std::cout << "\n"; }
        else if (i < data.size() - 1) { std::cout << ","; }
    }
    std::cout << "}";
}
// END OF EZPRINT TIME!!!

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

    int pop() {
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

int main() {
    Stack<int> intStack;
    intStack.push(5);
    intStack.push(6);

    intStack.print();
    intStack.pop();
    intStack.print();
    intStack.pop();
    intStack.print();

    Stack<const char*> charStack;
    charStack.push("H");
    charStack.push("e");
    charStack.push("l");
    charStack.push("l");
    charStack.push("o");
    charStack.push(" ");
    charStack.push("W");
    charStack.push("o");
    charStack.push("r");
    charStack.push("l");
    charStack.push("d");
    charStack.push("!");

    charStack.print();
    return 0;
}