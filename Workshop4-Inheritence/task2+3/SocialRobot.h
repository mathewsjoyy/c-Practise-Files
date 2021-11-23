# pragma once
#include <iostream>
#include "Robot.h"

class SocialRobot : public Robot
{
    public:
        SocialRobot(const std::string& name) : Robot(name) {}; // Calling base class constructor
        void sayHello() const;
        void setName(const std::string& name);
        void getName() const;
};