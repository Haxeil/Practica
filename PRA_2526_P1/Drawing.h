#ifndef DRAWING_H
#define DRAWING_H

#include <iostream>
#include "ListLinked.h"
#include "Shape.h"

class Drawing {
private:
    List<Shape*>* shapes;

public:
    Drawing() : shapes(new ListLinked<Shape*>()) {}
    ~Drawing();

    void add_front(Shape* shape) { shapes->prepend(shape); }
    void add_back(Shape* shape) { shapes->append(shape); }

    void print_all();
    double get_area_all_circles();
    void move_squares(double incX, double incY);
};

#endif