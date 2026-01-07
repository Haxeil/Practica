#include "Drawing.h"
#include "Circle.h"
#include "Square.h"

Drawing::~Drawing() {
    for (int i = 0; i < shapes->size(); ++i)
        delete shapes->get(i);
    delete shapes;
}

void Drawing::print_all() {
    std::cout << "Drawing contents:\n";
    for (int i = 0; i < shapes->size(); ++i) {
        shapes->get(i)->print();
        std::cout << std::endl;
    }
}

double Drawing::get_area_all_circles() {
    double total = 0.0;
    for (int i = 0; i < shapes->size(); ++i) {
        Circle* c = dynamic_cast<Circle*>(shapes->get(i));
        if (c) total += c->area();
    }
    return total;
}

void Drawing::move_squares(double incX, double incY) {
    for (int i = 0; i < shapes->size(); ++i) {
        Square* s = dynamic_cast<Square*>(shapes->get(i));
        if (s) s->translate(incX, incY);
    }
}