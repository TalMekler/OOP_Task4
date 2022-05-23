#include "Square.h"

Square::Square(double up, double down, double right, double left, const char *sn) : Quad(up, down, right, left, sn) {

}

Square::~Square() {
}

void Square::shiftX(int x) {
    m_centerPoint.setX(m_centerPoint.getX() + x);
}

void Square::shiftY(int y) {
    m_centerPoint.setY(m_centerPoint.getY() + y);
}
