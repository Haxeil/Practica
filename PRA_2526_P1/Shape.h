#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <stdexcept>
#include "Point2D.h"

class Shape {
protected:
    std::string color;

    void validate_color(const std::string& c) {
        if (c != "red" && c != "green" && c != "blue")
            throw std::invalid_argument("Color inválido");
    }

public:
    Shape() : color("red") {}
    Shape(std::string c) : color(c) { validate_color(c); }

    std::string get_color() const { return color; }
    void set_color(std::string c) { validate_color(c); color = c; }

    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void translate(double incX, double incY) = 0;
    virtual void print() const = 0;

    virtual ~Shape() = default;
};

#endif