#include "allShapes.h"
#include "Shape.h"
#include "Circle.h"
#include "Quad.h"
#include "Square.h"

allShapes::allShapes() : m_arr(nullptr), m_size(0) {}

allShapes::allShapes(const allShapes &other) {
    m_size = 0;
    for (int i = 0; i < other.getSize(); ++i) {
        addShape(other.m_arr[i]);
    }
}

allShapes::~allShapes() {
    for (int i = 0; i < m_size; ++i) {
        delete m_arr[i];
    }
    delete[] m_arr;
}

int allShapes::getSize() const {
    return m_size;
}

void allShapes::addShape(Shape *newShape) {
    Shape **tmp = new Shape *[m_size + 1];
    for (int i = 0; i < m_size; ++i) {
        tmp[i] = m_arr[i];
    }

    Square *sq = dynamic_cast<Square *>(newShape);
    Quad* qu = dynamic_cast<Quad *>(newShape);
    Circle* ci = dynamic_cast<Circle *>(newShape);
    if (sq)
        tmp[m_size] = new Square(*sq);
    else if(qu)
        tmp[m_size] = new Quad(*qu);
    else if(ci)
        tmp[m_size] = new Circle(*ci);

//    if (typeid(newShape) == typeid(Square))
//        tmp[m_size] = new Square(*(dynamic_cast<Square*>(newShape)));
//    else if (typeid(newShape) == typeid(Quad))
//        tmp[m_size] = new Quad(*(dynamic_cast<Quad*>(newShape)));
//    else if (typeid(newShape) == typeid(Circle))
//        tmp[m_size] = new Circle(*(dynamic_cast<Circle*>(newShape)));


    m_arr = tmp;
    m_size++;
}

void allShapes::removeShape(int index) {
    if (index < 0 || index >= m_size)
        throw "ERROR: Invalid index";

    Shape **tmp = new Shape *[m_size - 1];
    for (int i = 0, j = 0; i < m_size; ++i) {
        if (i != index) {
            tmp[j] = m_arr[i];
            j++;
        }
    }
//    delete m_arr[index];
    m_arr = tmp;
    m_size--;
}

int allShapes::totalArea() const {
    int res = 0;
    for (int i = 0; i < m_size; ++i) {
        res += m_arr[i]->calcArea();
    }

    return res;
}

int allShapes::totalPerimeter() const {
    int res = 0;
    for (int i = 0; i < m_size; ++i) {
        res += m_arr[i]->calcPerimeter();
    }

    return res;
}

int allShapes::totalCircleArea() const {
    int res = 0;
    Circle *tmp;
    for (int i = 0; i < m_size; ++i) {
        tmp = dynamic_cast<Circle *>(m_arr[i]);
        if (tmp)
            res += tmp->calcArea();
    }

    return res;
}

int allShapes::totalSquarePerimeter() const {
    int res = 0;
    Square *tmp;
    for (int i = 0; i < m_size; ++i) {
        tmp = dynamic_cast<Square *>(m_arr[i]);
        if (tmp)
            res += tmp->calcPerimeter();
    }

    return res;
}

const allShapes &allShapes::operator+=(Shape *newS) {
    addShape(newS);
    return *this;
}

Shape *allShapes::operator[](int ind) const {
    if (ind < 0 || ind >= m_size)
        throw "ERROR: Invalid index";

    return m_arr[ind];

}

allShapes allShapes::operator+(const allShapes &other) const {
    allShapes tmp(*this);
    for (int i = 0; i < other.getSize(); ++i) {
        tmp.addShape(other.m_arr[i]);
    }
    return tmp;
}

allShapes::operator int() const {
    return m_size;
}
