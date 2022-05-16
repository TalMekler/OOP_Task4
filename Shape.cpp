#include "Shape.h"

int Shape::s_totalNumOfShapes = 0;

Shape::Shape(const char *sn) {
    m_shapeName = nullptr;
    setShape(sn, Point(0, 0));
    s_totalNumOfShapes++;
}

Shape::Shape(const Shape &other) {
    m_shapeName = nullptr;
    *this = other;
    s_totalNumOfShapes++;
}

Shape::~Shape() {
    delete[] m_shapeName;
    s_totalNumOfShapes--;
}

void Shape::setName(const char *name) {
//    delete[] m_shapeName;
    m_shapeName = new char[strlen(name) + 1];
    strcpy(m_shapeName, name);
}

void Shape::setCenter(const Point &p) {
    m_centerPoint.setX(p.getX());
    m_centerPoint.setY(p.getY());
}

const char *Shape::getName() const {
    return m_shapeName;
}

Point Shape::getCenter() const {
    return m_centerPoint;
}

void Shape::setShape(const char *sn, const Point &other) {
    setName(sn);
    setCenter(other);
}

int Shape::numOfShapes() {
    return s_totalNumOfShapes;
}

const Shape &Shape::operator=(const Shape &other) {
    if (this == &other)
        return *this;

    setShape(other.getName(), other.getCenter());
    return *this;
}
