#include "Rectangle.h"

Rectangle::Rectangle() : Shape("red") {
    vs = new Point2D[N_VERTICES]{
        {-1, 0.5}, {1, 0.5}, {1, -0.5}, {-1, -0.5}
    };
}

Rectangle::Rectangle(std::string color, Point2D* vertices) : Shape(color) {
    if (!check(vertices)) throw std::invalid_argument("Provided vertices do not build a valid rectangle!");
    vs = new Point2D[N_VERTICES];
    for (int i = 0; i < N_VERTICES; ++i) vs[i] = vertices[i];
}

Rectangle::Rectangle(const Rectangle& r) : Shape(r.color) {
    vs = new Point2D[N_VERTICES];
    for (int i = 0; i < N_VERTICES; ++i) vs[i] = r.vs[i];
}

Rectangle::~Rectangle() { delete[] vs; }

Point2D Rectangle::get_vertex(int ind) const {
    if (ind < 0 || ind >= N_VERTICES) throw std::out_of_range("Índice inválido");
    return vs[ind];
}

Point2D Rectangle::operator[](int ind) const { return get_vertex(ind); }

void Rectangle::set_vertices(Point2D* vertices) {
    if (!check(vertices)) throw std::invalid_argument("Provided vertices do not build a valid rectangle!");
    for (int i = 0; i < N_VERTICES; ++i) vs[i] = vertices[i];
}

Rectangle& Rectangle::operator=(const Rectangle& r) {
    if (this != &r) {
        color = r.color;
        for (int i = 0; i < N_VERTICES; ++i) vs[i] = r.vs[i];
    }
    return *this;
}

double Rectangle::area() const {
    double w = Point2D::distance(vs[0], vs[1]);
    double h = Point2D::distance(vs[1], vs[2]);
    return w * h;
}

double Rectangle::perimeter() const {
    return 2 * (Point2D::distance(vs[0], vs[1]) + Point2D::distance(vs[1], vs[2]));
}

void Rectangle::translate(double incX, double incY) {
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i].x += incX;
        vs[i].y += incY;
    }
}

void Rectangle::print() {
    std::cout << "[Rectangle: color = " << color
              << "; v0 = " << vs[0] << "; v1 = " << vs[1]
              << "; v2 = " << vs[2] << "; v3 = " << vs[3] << "]";
}

std::ostream& operator<<(std::ostream& out, const Rectangle& r) {
    r.print();
    return out;
}