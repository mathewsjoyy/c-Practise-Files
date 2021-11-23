#include "AutonomousCar.h"
#include <math.h>

void AutonomousCar::UpdateLocation(const int& distance, const int& orientation)
{   
    const double PI = 3.14;
    this -> xCordinate += distance * cos(orientation * PI / 180);
    this -> yCordinate += distance * sin(orientation * PI / 180);

    std::cout << "\nThe car is now at (" << this -> xCordinate << ", " << this -> yCordinate << ")" << std::endl;
}