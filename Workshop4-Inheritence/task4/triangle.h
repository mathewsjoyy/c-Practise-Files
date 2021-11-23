#pragma once
#include "shape.h"

class Triangle : public Shape
{   
    private:
        double length;
    public:
        Triangle(const double& w = 0, const double& h = 0, const double& l = 0) : Shape(w, h), length(l) {};
        double area() const;
        Triangle operator+(const Triangle& t) const; // Option to add another triangle


};