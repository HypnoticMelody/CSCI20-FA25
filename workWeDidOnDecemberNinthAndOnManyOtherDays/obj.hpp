#include <iostream>
#include <stack>

/*
Stack calculator built using a monolithic object.

This means that the object will obfuscate the structure (stack) of evaluation.

This object represents something like a simple calculator taking numbers and evaluating.

- Problem: Representing numbers and operations | solved
We need an encoding for the numbers and operations of our calculator, lets use a struct.
    Our structure houses numbers for eval and characters for operations
    The operations will be represented by the following:
    - "+" addition
    - "-" subtraction
    - "*" multiplication
    - "/" division
    - "=" eval

- Problem: What are the basic operations of this calculator | solved
    - addition
    - subtraction
    - multiplication
    - division
    - evaluation

- Problem: im getting so bored now oh my GODDDDDDDDDD
im just gonna play on my phone now lol
*/

class Calc {
private:
    struct Dicho {
        int num;
        bool isOp;
        
        void set_num(int);
    };
    
    std::stack<Dicho> st;
    
public:
    Calc();
    Dicho collapse();
};
