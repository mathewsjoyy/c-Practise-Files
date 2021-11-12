#include "student.h"
#include <iostream>
#include <ctime>

Student::Student(const std::string& name,const int& age){
    this -> name = name;
    this -> age = age;

    // This is how we get our current year
    std::time_t t = std::time(nullptr);
    std::tm *const pTInfo = std::localtime(&t);

    std::string email = name;
    email += std::to_string(age);
    std::string year = std::to_string(1900 + pTInfo->tm_year); 
    email += year;

    this -> student_email = email;
}

void Student::printDetails(){
    std::cout << "Name: " << this -> name << " Age: " << this -> age << " Email: " << this -> student_email << "\n";
}

void Student::addModule(const std::string module){
    this -> enrolledModules.push_back(module);
}