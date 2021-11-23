#include <iostream>

int add(int a, int b)
{
    return a + b;
}

float add(int a, int b, std::string flag)
{
    return static_cast<float>(a + b);
}

float addFloatInt(float a, int b)
{
    return static_cast<float>(a + b);
}

float addIntFloat(int a, float b)
{
    return static_cast<float>(a + b);
}

float addFloatFloat(float a, float b)
{
    return static_cast<float>(a + b);
}


int main(){

    std::cout << add(1, 2) << std::endl;
    std::cout << add(1.0, 2.0, "float") << std::endl;
    std::cout << addFloatInt(1.0, 2) << std::endl;
    std::cout << addIntFloat(1, 2.0) << std::endl;
    std::cout << addFloatFloat(1.0, 2.0) << std::endl;


    return 0;
}