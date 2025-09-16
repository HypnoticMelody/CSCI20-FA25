#include <iostream>
#include <cstdio>
#include <array>
#include <vector>
#include <string>

int main() {
    // array testing
    std::array<std::string, 3> a{"Hey!", "Hello!", "Howdy!"};

    //print each item
    std::string test;
    
    for (size_t i = 0; i < a.size(); i++)
        test = a[i];
        std::printf(test.c_str()); //cant do this buffer stuff in a for loop :c
    std::printf("\n");


    // vector testing
    std::vector<std::string> v = {"Bye!", "See ya!", "Hmm..."};
    v.push_back("Ciao!");
    v.push_back("Sayonara!");
    v[2] = "Toodles!";
    
    // print each item
    for (size_t i = 0; i < v.size(); i++)
        std::printf("%s", v[i]); //bad method :c
    std::printf("\n");


    //inception testing
    
    std::vector<std::vector<int>> matrix = {
        {0,1,2},
        {3,4,5},
        {6,7,8}
    };

    for (size_t i = 0; i < matrix.size(); i++)
        // std::printf("[");
        for (size_t j = 0; j < matrix[i].size(); j++)
            std::printf("%i ", matrix[i][j]);
        // std::printf("], ");
    std::printf("\n");


    std::printf("\n===ACTUAL ASSIGNMENT===\n\n");
    //// OKAY HERES THE ACTUAL STUFF THAT IM SUPPOSED TO BE DOING HAHAHAHHAA

    std::array<int,5> a5 = {0,5,2,4,1};
    std::array<bool,1> a1 = {true};
    std::array<int,2> a2 = {-1,1};

    std::printf("%i\n", a5[0]);
    std::printf("%i\n", a1[0]);
    std::printf("%i\n", a2[0]);

    std::vector<int> v3 = {1,5,10};
    std::vector<bool> v10 = {false,false,false,false,false,false,true,false,false,false};
    std::vector<int> v7 = {0,-1,1,-2,2,-3,3};

    std::printf("%i\n", v3[2]);
    std::printf("%i\n", v10[6]); //woah this prints a wacko value, fun!
    std::printf("%i\n", v7[3]);

    return 0;
}