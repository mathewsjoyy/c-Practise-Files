#pragma once
#include "Robot.h"

class IndustrialRobot : public Robot
{
    public:
        IndustrialRobot(const std::string& name) : Robot(name) {};
        void workHarder() {work(); work();};
};