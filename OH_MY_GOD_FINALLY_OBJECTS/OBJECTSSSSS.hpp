#include <iostream>

class A {
    private:
        int b;
        int c;
    public:
        A();
        void road_in (int, int);
        int road_out ();
};

A::A() {
    b = 5;
    c = 5;
}