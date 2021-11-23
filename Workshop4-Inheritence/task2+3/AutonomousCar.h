#pragma once
#include <iostream>
#include "Robot.h"

class AutonomousCar : public Robot
{
    public:
        AutonomousCar(const std::string& name) : Robot(name){};
        void UpdateLocation(const int& distance, const int& orientation);
        void work() const {std::cout << "I am an autonomous car and I don't work, but I drive!" << std::endl;};

    private:
        std::string currentLocation = "N/A";
        int xCordinate = 0, yCordinate = 0;

};