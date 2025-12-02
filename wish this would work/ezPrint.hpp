#include <iostream>
#include <vector>

// Meet ezPrint! They can handle vectors of any dimension, along with any type that can be normally printed by std::cout! They are very good at enraging those who hate std::cout.
template <typename T>
void ezPrint(T data) {
    std::cout << data;
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