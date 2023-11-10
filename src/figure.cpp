#pragma once
#include "figure.h"

template <Number T>
std::ostream& operator<<(std::ostream& out, const Figure<T>& figure) {
    // Вывод фигуры
    out << "Фигура " << figure.getName() << ":\n";
    for (int i = 0; i < figure.getVertices(); ++i)
        out << figure._array[i] << " ";
    out << "\n";
    return out;
}
template <Number T>
std::istream& operator>>(std::istream& in, Figure<T>& figure) {
    // Ввод фигуры
    for (int i = 0; i < figure.getVertices(); ++i)
        in >> figure._array[i];
    return in;
}

template <Number T>
void Figure<T>::builder(std::vector<Point2D<T>>& points) {
    std::cout << "Я общий билдер. Я был вызван для класса " << getName() << " с количеством вершин " << getVertices() << std::endl;
    for (int i = 0; i < getVertices(); ++i) {
        _array[i] = points[i];
    }
}
template <Number T>
void Figure<T>::constructor(std::vector<Point2D<T>>& points) {
    std::cout << "Я общий конструктор" << std::endl;
    _array = new Point2D<T>[getVertices()];
    builder(points);
}
// Figure::Figure(std::vector<Point2D>& points) {
//     constructor(points);
// }

// Figure::Figure(const Figure& other) {
//     std::vector<Point2D> points = other.getPoints();

//     constructor(points);
// }
template <Number T>
Figure<T>::Figure(Figure&& other, int vertices) {
    std::cout << "Я конструктор перемещения" << std::endl;
    _array = other._array;
    other._array = new Point2D<T>[vertices];
}
template <Number T>
Figure<T>::~Figure() {
    std::cout << "Я деструктор" << std::endl;
    delete[] _array;
}

// Figure& Figure::operator=(const Figure& other) {
//     std::cout << "Я общий оператор копирующего присваивания. Я был вызван для класса " << getName() << " с количеством вершин " << getVertices() << std::endl;
//     std::vector<Point2D> points = other.getPoints();

//     builder(points);

//     return *this;
// }
template <Number T>
Figure<T>& Figure<T>::operator=(Figure&& other) {
    std::cout << "Я общий оператор перемещающего присваивания. Я был вызван для класса " << getName() << " с количеством вершин " << getVertices() << std::endl;
    _array = other._array;
    other._array = new Point2D<T>[getVertices()];
    return *this;
}

template <Number T>
std::vector<Point2D<T>> Figure<T>::getPoints() const {
    std::vector<Point2D<T>> points(getVertices());
    for (int i = 0; i < getVertices(); ++i)
        points[i] = _array[i];
    return points;
}

template <Number T>
Point2D<T> getIntersectionPoint(Point2D<T>& s1, Point2D<T>& e1, Point2D<T>& s2, Point2D<T>& e2) {
    // s и e - сокращение от start и end

    // Имеем уравнение двух прямых по двум точкам
    // Так как ищем точку пересечения, имеем две неизвестные - 'x' и 'y'
    // Из уравнения первой прямой выражаем 'x', он зависит от 'y'
    // Из уравнения второй прямой выражаем 'y', он зависит от 'x'
    // Получаем систему двух линейных уравнений двух переменных (x и y)
    // Решаем по правилу Крамера

    // Матрицу неоднородной системы линейных алгебраических уравнений представим в виде:
    // (a b | e)
    // (c d | f)

    T
    a = -1,
    b = (e1.x() - s1.x()) / (e1.y() - s1.y()),
    c = (e2.y() - s2.y()) / (e2.x() - s2.x()),
    d = -1,
    e = s1.y() * b - s1.x(),
    f = s2.x() * c - s2.y(),
    det = a * d - b * c,
    det1 = e * d - b * f,
    det2 = a * f - e * c,
    x = det1 / det,
    y = det2 / det;

    return Point2D<T>(x, y);
}

template <Number T>
T getLengthVector(Point2D<T>& a, Point2D<T>& b) {
    T
    x = a.x() - b.x(),
    y = a.y() - b.y();
    return sqrt(x * x + y * y);
}