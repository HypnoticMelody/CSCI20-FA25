#include "obj.hpp"


int main() {
    Calc object;

    object.push_num(1);
    object.push_num(1);
    object.push_op(0);
    object.push_num(2);
    object.push_op(2);
    
    object.collapse(); // (1 + 1) * 2

    std::cout << object.pop_top();

    return 0;
}


// Triggers a collapse of the calculator: calculates stack utilizing reverse polish notation. Leaves the end result in the calculator.
void Calc::collapse() { inner_collapse(); return; }

Calc::Dicho Calc::inner_collapse() {
    Dicho d0 = st.top();
    st.pop();

    Dicho d1 = st.top();
    if (d1.isOp) {
        // std::cout << "d1 collapse\n";
        push(d1);
        d1 = inner_collapse();
    }
    st.pop();

    Dicho d2 = st.top();
    if (d2.isOp) {
        // std::cout << "d2 collapse\n";
        push(d2);
        d2 = inner_collapse();
    }
    st.pop();

    Dicho output;
    output.isOp = false;

    switch (d0.num) {
    case (0): // add
        output.num = (d1.num + d2.num);
        break;
    case (1): // sub
        output.num = (d1.num - d2.num);
        break;
    case (2): // mult
        output.num = (d1.num * d2.num);
        break;
    case (3): // div
        output.num = (d1.num / d2.num);
        break;
    case (4): // mod
        output.num = (d1.num % d2.num);
        break;
    }
    st.push(output);

    return output;
}

// Pushes a number to the calculator.
void Calc::push_num(int _num) {
    Dicho number;
    number.num = _num;
    number.isOp = false;
    st.push(number);
}

// Pushes an operator (0:addition, 1:subtraction, 2:multiplication, 3:division, 4:mod) to the calculator.
void Calc::push_op(int op) {
    Dicho operation;
    operation.num = op;
    operation.isOp = true;
    st.push(operation);
}

// Returns the integer at the top of the calculator.
int Calc::pop_top() {
    int output = st.top().num;
    st.pop();
    return output;
}

void Calc::push(Dicho dichotomy) { st.push(dichotomy); }