#pragma once
#include <string>
#include <vector>
#include <iostream>

class Student {
    private:
        std::string name;
        int age;
        std::string student_email;
        std::vector<std::string> enrolledModules;

    public:
        Student(const std::string& name,const int& age);
        void addModule(const std::string module);
        void printDetails();
};