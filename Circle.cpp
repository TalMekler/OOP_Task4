#include "Circle.h"
#define PI 3.14159
Circle::Circle(double r, const char *sn) : Shape(sn), m_radius(r) { }

Circle::Circle(const Circle &other) {
    *this = other;
}

Circle::~Circle() {
}

double Circle::getRadius() const {
    return m_radius;
}

void Circle::setRadius(double r) {
    m_radius = r;
}

int Circle::calcArea() const {
    return (int)(PI * m_radius * m_radius);
}

int Circle::calcPerimeter() const {
    return (int)(2 * PI * m_radius);
}

const Circle& Circle::operator=(const Circle &other) {
    if(this == &other)
        return *this;

    setShape(other.getName(), other.getCenter());
    setRadius(other.getRadius());

    return *this;
}

const Circle& Circle::operator=(const char *name) {
    setName(name);
    return *this;
}

Circle operator+(int r, const Circle &other) {
    return Circle(r+other.getRadius());
}
