#include <iostream>
#include <vector>
#include <algorithm>


enum class Operation {NUM, ADD, SUB, MULT, DIV, MOD};

struct Point {
    Operation operation;
    int num;

    Point(Operation _operation) {
        operation = _operation;
    }

    Point(int _num) {
        operation = Operation::NUM;
        num = _num;
    }

    void print() {
        switch (operation) {
            case (Operation::NUM):
                std::cout << num;
                break;
            case (Operation::ADD):
                std::cout << "+";
                break;
            case (Operation::SUB):
                std::cout << "-";
                break;
            case (Operation::MULT):
                std::cout << "*";
                break;
            case (Operation::DIV):
                std::cout << "/";
                break;
            case (Operation::MOD):
                std::cout << "%";
                break;
        }
    }
};

void ezPrint(Point data) {
    data.print();
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

struct RPNStack {
    size_t size = 0;
    std::vector<Point> data = {};

    void push(Point e) {
        data.push_back(e);
        size = size + 1;
        // std::cout << "Pushed on: " << e << "\n";
        return;
    }
    void pushInt(int e) {
        Point eNew(e);
        data.push_back(eNew);
        size = size + 1;
        // std::cout << "Pushed on: " << e << "\n";
        return;
    }
    void pushOp(Operation e) {
        Point eNew(e);
        data.push_back(eNew);
        size = size + 1;
        // std::cout << "Pushed on: " << e << "\n";
        return;
    }

    Point pop() {
        size = size - 1;
        Point value = data[size];
        data.pop_back();
        // std::cout << "Popped off: " << value << "\n";
        return value;
    }

    void print() {
        ezPrint(data, false);
        std::cout << "\n";
        return;
    }

    void collapse() {
        Point p0 = pop();

        // ezPrint(p0);

        if (p0.operation == Operation::NUM) {
            push(p0);
            return;
        }

        collapse();
        Point p1 = pop();
        collapse();
        Point p2 = pop();
        
        switch (p0.operation) {
            case (Operation::ADD):
                push(p1.num + p2.num);
                break;
            case (Operation::SUB):
                push(p1.num - p2.num);
                break;
            case (Operation::MULT):
                push(p1.num * p2.num);
                break;
            case (Operation::DIV):
                push(p1.num / p2.num);
                break;
            case (Operation::MOD):
                push(p1.num % p2.num);
                break;
        }
    }
};

int main() {
    RPNStack RPN;

    
    RPN.pushInt(1);
    RPN.pushInt(1);
    RPN.pushOp(Operation::ADD);
    RPN.pushInt(2);
    RPN.pushOp(Operation::ADD);
    RPN.pushInt(5);
    RPN.pushOp(Operation::MULT);

    RPN.print();
    RPN.collapse(); // (((1+1)+2)*5)
    RPN.print();


    return 0;
}