#include <iostream>
#include <string>

class rgbColor {
    private: // vars
        int r;
        int g;
        int b;
    public: // methods
        void set(int _r, int _g, int _b) {
            r = _r;
            g = _g;
            b = _b;
        }
        std::string str_out() const {
            return "<" + std::to_string(r) + "," + std::to_string(g) + "," + std::to_string(b) + ">";
        }
    public: // constructors
        rgbColor(int _r, int _g, int _b) {
            r = _r;
            g = _g;
            b = _b;
        }
        rgbColor() {
            set(0, 0, 0);
        }
    public: // palette
        static const rgbColor RED;
        static const rgbColor GREEN;
        static const rgbColor BLUE;
        
        static const rgbColor CYAN;
};

const rgbColor rgbColor::RED = rgbColor(255,0,0);
const rgbColor rgbColor::GREEN = rgbColor(0,255,0);
const rgbColor rgbColor::BLUE = rgbColor(0,0,255);

const rgbColor rgbColor::CYAN = rgbColor(0,206,209);

struct thing {
    public:
        rgbColor color;
        std::string name;
};

int main() {
    thing newThing;
    newThing.color = rgbColor::CYAN;

    std::cout << newThing.color.str_out();

    return 0;
}
