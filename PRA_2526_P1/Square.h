#ifndef SQUARE_H
#define SQUARE_H

#include "Rectangle.h"

class Square : public Rectangle {
private:
    static bool check(Point2D* vertices) {
        double a = Point2D::distance(vertices[0], vertices[1]);
        double b = Point2D::distance(vertices[1], vertices[2]);
        double c = Point2D::distance(vertices[2], vertices[3]);
        double d = Point2D::distance(vertices[3], vertices[0]);
        return a == b && b == c && c == d;
    }

public:
    Square();
    Square(std::string color, Point2D* vertices);

    void set_vertices(Point2D* vertices) override;
    void print() override;

    friend std::ostream& operator<<(std::ostream& out, const Square& s);
};

#endif