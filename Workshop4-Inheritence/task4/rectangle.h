#pragma once
#include "shape.h"

class Rectangle : public Shape
{
    public:
        Rectangle(const double& w = 0, const double& h = 0) : Shape(w, h) {};
        double area() const;
        Rectangle operator+(const Rectangle& r) const; // Option to add another rectangle
};