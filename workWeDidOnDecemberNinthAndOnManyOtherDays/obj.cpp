#include "obj.hpp"


int main() {
    return 0;
}


Calc::Dicho::set_num(int _num) {
    num = _num;
    isOp = false;
}

Calc::Dicho::set_op(int _num) {
    num = _num;
    isOp = true;
}

Calc::collapse() {
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
}