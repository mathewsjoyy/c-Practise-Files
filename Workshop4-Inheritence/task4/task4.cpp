#include <iostream>
#include "rectangle.h"
#include "triangle.h"

int main(){
    
    Rectangle r1(2,3);
    Rectangle r2(3,4);

    Triangle t1(3,4);
    Triangle t2(4,5);

    std::cout << "Area of r1 rectangle >> " << r1.area() << std::endl;
    std::cout << "Area of t1 triangle >> " << t1.area() << std::endl;

    Rectangle s1 = r1 + r2;
    std::cout << "Area of s1 rectangle >> " << s1.area() << std::endl;

    Triangle s2 = t1 + t2;
    std::cout << "Area of s2 triangle >> " << s2.area() << std::endl;

    return 0;
}