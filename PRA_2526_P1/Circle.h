#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include <cmath>
#include "Shape.h"

class Circle : public Shape {
private:
    Point2D center;
    double radius;

public:
    Circle() : Shape(), center(0,0), radius(1) {}
    Circle(std::string col, Point2D c, double r) : Shape(col), center(c), radius(r) {}

    Point2D get_center() const { return center; }
    void set_center(Point2D p) { center = p; }
    double get_radius() const { return radius; }
    void set_radius(double r) { radius = r; }

    double area() const override { return 3.141592 * radius * radius; }
    double perimeter() const override { return 2 * 3.141592 * radius; }

    void translate(double incX, double incY) override {
        center.x += incX;
        center.y += incY;
    }

    void print() const override {
        std::cout << "[Circle: color = " << color
                  << "; center = " << center
                  << "; radius = " << radius << "]";
    }

    friend std::ostream& operator<<(std::ostream& out, const Circle& c) {
        c.print();
        return out;
    }
};

#endif
