#include "triangle.h"

double Triangle::area() const
{
    return (width * height) / 2;
}

Triangle Triangle::operator+(const Triangle& t) const
{
    return Triangle(this -> width + t.width, this -> height + t.height, this -> length + t.length);
}