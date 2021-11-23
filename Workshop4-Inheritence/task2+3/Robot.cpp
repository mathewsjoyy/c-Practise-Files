# include "Robot.h"

void Robot::work(){
    workUnit++; 
    _history -> push_back(workUnit);

    std::cout << name << " is working. > " << workUnit <<"\n";
}

void Robot::printWork() const {
    std::cout << "Robot " << name << " has done the following work: ";

    for(const int& record : *_history){
        std::cout << record << " ";
    }

    std::cout << std::endl;
}