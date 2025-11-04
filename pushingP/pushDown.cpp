#include <iostream>
#include <vector>



struct Stack {
    size_t size = 0;
    std::vector<int> data = {};

    void push(int e) {
        data.push_back(e);
        size = size + 1;
        return;
    }

    int pop() {
        size = size - 1;
        int value = data[size];
        data.pop_back();
        return value;
    }

    void print() {
        std::cout << "{";
        for (size_t i = 0; i < size; i++) {
            std::cout << data[i] << ", ";
        }
        std::cout << "}\n";
        return;
    }
};

int main() {
    Stack s; // stuck at array size 5 :(
    s.push(5);
    s.push(6);

    s.print();
    std::cout << s.pop() << "\n";
    s.print();
    std::cout << s.pop() << "\n";
    s.print();
    return 0;
}