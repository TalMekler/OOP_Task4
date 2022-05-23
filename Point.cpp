#include "Point.h"

Point::Point(int x, int y) {
    setPoint(x, y);
}

Point::Point(const Point &other) {
    setPoint(other);
}

Point::~Point() {

}

int Point::getX() const {
    return m_x;
}

int Point::getY() const {
    return m_y;
}

void Point::setX(int x) {
    m_x = x;
}

void Point::setY(int y) {
    m_y = y;
}

void Point::setPoint(int x, int y) {
    m_x = x;
    m_y = y;
}

void Point::setPoint(const Point &other) {
    m_x = other.getX();
    m_y = other.getY();
}

bool Point::operator==(const Point &other) const {
    if (this == &other)
        return true;

    if (m_x == other.getX() && m_y == other.getY())
        return true;

    return false;
}

bool Point::operator!=(const Point &other) const {
    return !(*this == other);
}

Point Point::operator+(int num) const {
    return Point(m_x + num, m_y + num);
}

const Point &Point::operator+=(int num) {
    m_x += num;
    m_y += num;
    return *this;
}

Point::operator int() const {
    return m_x + m_y;
}

Point Point::operator+(const Point &other) const {
    return Point(m_x + other.getX(), m_y + other.getY());
}

Point Point::operator++(int) {
    Point tmp(*this);
    m_x++;
    m_y++;
    return tmp;
}

const Point &Point::operator++() {
    m_x++;
    m_y++;
    return *this;
}

Point operator*(int num, const Point &other) {
    return Point(other.getX() * num, other.getY() * num);
}