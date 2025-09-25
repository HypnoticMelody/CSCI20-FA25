#include <iostream>
#include <string>

class rgbColor { // Shouldnt be using class for this! struct is a better idea for this type of stuff
    public:
        int r;
        int g;
        int b;
        int setColor(int _r, int _g, int _b) {
            r = _r;
            g = _g;
            b = _b;
        };
};

class thing { // Shouldnt be using class for this! struct is a better idea for this type of stuff
    public:
        rgbColor color;
        std::string name;
};

std::string rgbToStr(rgbColor color) {
    return "<" + std::to_string(color.r) + "," + std::to_string(color.g) + "," + std::to_string(color.b) + ">";
};

int main() {
    thing newThing;
    newThing.color.setColor(0,206,209);

    std::cout << rgbToStr(newThing.color);

    return 0;
}
