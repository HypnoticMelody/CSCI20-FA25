#include "OBJECTSSSSS.hpp"


int main () {
    int b = 1;
    int c = 4;
    A squid;
    squid.road_in(5,12);
    int d = squid.road_out;
    

    return 0;
}

void A::road_in(int _b, int _c) {
    b = _b;
    c = _c;
}

int A::road_out() {
    return b + c;
}