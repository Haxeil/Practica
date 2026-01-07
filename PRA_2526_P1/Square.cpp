#include "Square.h"

Square::Square() : Rectangle() {
    delete[] vs;
    vs = new Point2D[N_VERTICES]{
        {-1,1}, {1,1}, {1,-1}, {-1,-1}
    };
}

Square::Square(std::string color, Point2D* vertices) : Rectangle(color, vertices) {
    if (!check(vertices)) throw std::invalid_argument("Provided vertices do not build a valid square!");
}

void Square::set_vertices(Point2D* vertices) {
    if (!check(vertices)) throw std::invalid_argument("Provided vertices do not build a valid square!");
    Rectangle::set_vertices(vertices);
}

void Square::print() {
    std::cout << "[Square: color = " << color
              << "; v0 = " << vs[0] << "; v1 = " << vs[1]
              << "; v2 = " << vs[2] << "; v3 = " << vs[3] << "]";
}

std::ostream& operator<<(std::ostream& out, const Square& s) {
    s.print();
    return out;
}