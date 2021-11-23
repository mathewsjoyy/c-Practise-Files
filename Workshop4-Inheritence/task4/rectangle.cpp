#include "rectangle.h"

double Rectangle::area() const {
    return width * height;
}

Rectangle Rectangle::operator+(const Rectangle& r) const
{
    return Rectangle(this -> width + r.width, this -> height + r.height);
}