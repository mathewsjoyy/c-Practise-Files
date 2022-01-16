#include <iostream>
#include <algorithm>
#include <typeinfo>

void variableType(int num){
    std::cout << num << " - This variable can be a " << typeid(num).name() << std::endl;
} 

void variableType(double num){
    std::cout << num << " - This variable can be a " << typeid(num).name() << std::endl;
}

void variableType(std::string input){
    std::cout << input << " - This variable can be a string string" << std::endl;
}



int main()
{
    std::cout << "Enter something blud: ";
    
    std::string num; 
    std::cin >> num;

    variableType(num); // string

    try{
        variableType(std::stoi(num)); // convert to int
    }
    catch(std::exception&){
        std::cout << "Input cannot be a int: " << std::endl;
    }

    try{
        variableType(std::stod(num)); // convert to double
    }
    catch(std::exception&){
        std::cout << "Input cannot be a double " << std::endl;
    }

    return 0;
}