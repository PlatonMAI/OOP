#include "figure.h"

std::ostream& operator<<(std::ostream& out, const Figure& figure) {
    // Вывод фигуры
    out << "Фигура " << figure.getName() << ":\n";
    for (int i = 0; i < figure.getVertices(); ++i)
        out << figure._array[i] << " ";
    out << "\n";
    return out;
}
std::istream& operator>>(std::istream& in, Figure& figure) {
    // Ввод фигуры
    for (int i = 0; i < figure.getVertices(); ++i)
        in >> figure._array[i];
    return in;
}

void Figure::builder(std::vector<Point2D>& points) {
    std::cout << "Я общий билдер. Я был вызван для класса " << getName() << " с количеством вершин " << getVertices() << std::endl;
    for (int i = 0; i < getVertices(); ++i) {
        _array[i] = points[i];
    }
}
void Figure::constructor(std::vector<Point2D>& points) {
    std::cout << "Я общий конструктор" << std::endl;
    _array = new Point2D[getVertices()];
    builder(points);
}
// Figure::Figure(std::vector<Point2D>& points) {
//     constructor(points);
// }

// Figure::Figure(const Figure& other) {
//     std::vector<Point2D> points = other.getPoints();

//     constructor(points);
// }
Figure::Figure(Figure&& other, int vertices) {
    std::cout << "Я конструктор перемещения" << std::endl;
    _array = other._array;
    other._array = new Point2D[vertices];
}
Figure::~Figure() {
    std::cout << "Я деструктор" << std::endl;
    delete[] _array;
}

// Figure& Figure::operator=(const Figure& other) {
//     std::cout << "Я общий оператор копирующего присваивания. Я был вызван для класса " << getName() << " с количеством вершин " << getVertices() << std::endl;
//     std::vector<Point2D> points = other.getPoints();

//     builder(points);

//     return *this;
// }
Figure& Figure::operator=(Figure&& other) {
    std::cout << "Я общий оператор перемещающего присваивания. Я был вызван для класса " << getName() << " с количеством вершин " << getVertices() << std::endl;
    _array = other._array;
    other._array = new Point2D[getVertices()];
    return *this;
}

std::vector<Point2D> Figure::getPoints() const {
    std::vector<Point2D> points(getVertices());
    for (int i = 0; i < getVertices(); ++i)
        points[i] = _array[i];
    return points;
}

Point2D getIntersectionPoint(Point2D& s1, Point2D& e1, Point2D& s2, Point2D& e2) {
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

    double
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

    return Point2D(x, y);
}

double getLengthVector(Point2D& a, Point2D& b) {
    double
    x = a.x() - b.x(),
    y = a.y() - b.y();
    return sqrt(x * x + y * y);
}