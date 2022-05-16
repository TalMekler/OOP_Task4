#include "Quad.h"

Quad::Quad(double up, double down, double right, double left, const char *sn) : Shape(sn) {
    m_up = up;
    m_down = down;
    m_right = right;
    m_left = left;
}

Quad::Quad(const Quad &other) {
    m_up = other.m_up;
    m_down = other.m_down;
    m_right = other.m_right;
    m_left = other.m_left;
}

Quad::~Quad() {
}

int Quad::calcArea() const {
    return (int)(m_right * m_up);
}

int Quad::calcPerimeter() const {
    return (int)(m_up + m_down + m_right + m_left);
}
