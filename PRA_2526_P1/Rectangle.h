#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include <stdexcept>
#include "Shape.h"

class Rectangle : public Shape {
protected:
    Point2D* vs;
    static const int N_VERTICES = 4;

    static bool check(Point2D* vertices) {
        double a = Point2D::distance(vertices[0], vertices[1]);
        double b = Point2D::distance(vertices[2], vertices[3]);
        double c = Point2D::distance(vertices[1], vertices[2]);
        double d = Point2D::distance(vertices[3], vertices[0]);
        return a == b && c == d;
    }

public:
    Rectangle();
    Rectangle(std::string color, Point2D* vertices);
    Rectangle(const Rectangle& r);
    ~Rectangle();

    Point2D get_vertex(int ind) const;
    Point2D operator[](int ind) const;
    virtual void set_vertices(Point2D* vertices);

    Rectangle& operator=(const Rectangle& r);

    double area() const override;
    double perimeter() const override;
    void translate(double incX, double incY) override;
    virtual void print() override;

    friend std::ostream& operator<<(std::ostream& out, const Rectangle& r);
};

#endif