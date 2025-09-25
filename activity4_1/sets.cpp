#include <iostream>
#include <cstdio> // printf lib
#include <array> // array lib
#include <vector> // vec lib
#include <string> // string lib

int main() {
    // array testing
    std::array<std::string, 3> a{"Hey!", "Hello!", "Howdy!"};

    //print each item
    std::string test;
    
    for (size_t i = 0; i < a.size(); i++)
        test = a[i];
        std::printf((test + "\n").c_str()); //cant do this buffer stuff in a for loop :c
        std::fflush(stdout); //BUT WAIT, I CAN!!!!
    //WHY DOES IT STILL NOT WORK???????

    // vector testing
    std::vector<std::string> v = {"Bye!", "See ya!", "Uhhh..."};
    v.push_back("Ciao!");
    v.push_back("Sayonara!");
    v[2] = "Toodles!";
    
    // print each item
    for (size_t i = 0; i < v.size(); i++)
        std::printf("%s\n", v[i]); //bad method :c


    //inception testing
    std::vector<std::vector<int>> matrix = {
        {0,1,2},
        {3,4,5},
        {6,7,8}
    };

    for (size_t i = 0; i < matrix.size(); i++)
        for (size_t j = 0; j < matrix[i].size(); j++)
            std::printf("%i ", matrix[i][j]); //WHY DOES IT WORK INSIDE NESTED FOR LOOPS????????? WHAT EVEN???????????
    std::printf("\n");


    //NEW IDEA!!!!!: a while loop that goes over commands that i put into a vector! idk if that's smart but let's do it!
    // std::array<std::string, 5> aStrings = {"Let's ", "see ", "if ", "this ", "works!"};
    //
    // std::vector<std::array<std::string, 2>> commandsBuffer = {};
    // for (size_t i = 0; i < aStrings.size(); i++)
    //     commandsBuffer.push_back({"std::printf", aStrings[i]});
    //
    // std::string doThisPlease = "";
    // std::string withThisPlease = "";
    // while (!commandsBuffer.empty() && false)
    //     doThisPlease = commandsBuffer.back()[0];
    //     withThisPlease = commandsBuffer.back()[1];
    //     if (doThisPlease == "std::printf") {
    //         std::printf(withThisPlease.c_str());
    //     } else {
    //         std::printf("dude what");
    //     }
    //     commandsBuffer.pop_back();
    // ...I give up. I don't wanna continue trying to make this work.

    std::printf("\n===ACTUAL ASSIGNMENT===\n\n");
    //// OKAY HERES THE ACTUAL STUFF THAT IM SUPPOSED TO BE DOING HAHAHAHHAA

    // also, i did like, both size types and data types
    // so like.... doouuuuubble extra credit???? pretty pleaseeee????? (imagine me giving you doe eyes)

    std::array<int,5> a5 = {0,5,2,4,1};
    std::array<bool,1> a1 = {true};
    std::array<std::string,2> a2 = {"Arrays are fun!\n","...NOT!!!\n"};

    std::printf("%i\n", a5[0]);
    std::printf("%i\n", a1[0]);
    std::printf(a2[0].c_str());

    std::vector<int> v3 = {1,5,10};
    std::vector<bool> v10 = {false,false,false,false,false,false,true,false,false,false};
    std::vector<std::string> v1 = {"Vectors are fun!\n"};

    std::printf("%i\n", v3[2]);
    std::printf("%i\n", v10[6]); //woah this prints a wacko value! fun!
    std::printf(v1[0].c_str());

    return 0;
}