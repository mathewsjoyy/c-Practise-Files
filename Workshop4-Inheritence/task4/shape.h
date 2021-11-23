#pragma once

class Shape {

    protected:
        double width;
        double height;
    
    public:
        Shape(const double& w = 0, const double& h = 0) : width(w), height(h) {};
        int getWidth() const { return width; };
        int getHeight() const { return height; };

};