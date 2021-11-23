#include "SocialRobot.h"

void SocialRobot::sayHello() const {
    std::cout << "Hello, I am a social robot" << std::endl;
};

void SocialRobot::setName(const std::string& name) {
    Robot::name = name;
};

void SocialRobot::getName() const {
    std::cout << "My name is " << name << std::endl;
};