#include "obj.hpp"


int main() {
    Calc object;


    return 0;
}


Dicho Calc::collapse() {
    Dicho d0 = st.pop();

    Dicho d1 = st.pop();
    if (d1.isOp) {
        d1 = collapse();
    }

    Dicho d2 = st.pop();
    if (d1.isOp) {
        d2 = collapse();
    }

    Dicho output;
    switch (d0.num) {
    case (0): // add
        output.set_num(d1.num + d2.num);
        break;
    case (1): // sub
        output.set_num(d1.num - d2.num);
        break;
    case (2): // mult
        output.set_num(d1.num * d2.num);
        break;
    case (3): // div
        output.set_num(d1.num / d2.num);
        break;
    case (4): // mod
        output.set_num(d1.num % d2.num);
        break;
    }
    st.push(output);

    return;
}

Calc::more(int num) {
    
}

Calc::more(char op) {
    
}


Calc::Dicho(int _num) {
    num = _num;
    isOp = false;
}

Calc::Dicho(char op) {
    switch (op) {
    case ("+"):
        num = 0;
        break;
    case ("-"):
        num = 0;
        break;
    case ("*"):
        num = 0;
        break;
    case ("/"):
        num = 0;
        break;
    case ("%"):
        num = 0;
        break;
    }
    isOp = true;
}

Calc::Dicho::set_op(int _num) {
    num = _num;
    isOp = true;
}