#include <triangle.h>
#include <triangleValidator.h>

Triangle::Triangle(std::vector<Point2D>& points) {
    constructor(points);
}
Triangle::Triangle(const Triangle& other) {
    std::cout << "Конструктор копирования треугольника" << std::endl;
    std::vector<Point2D> points = other.getPoints();

    constructor(points);
}

Triangle& Triangle::operator=(const Triangle& other) {
    std::cout << "Оператор копирующего присваивания треугольника " << std::endl;
    std::vector<Point2D> points = other.getPoints();

    builder(points);

    return *this;
}

Point2D Triangle::get_center() {
    // Геометрический центр треугольника - точка пересечения медиан
    // Так как все медианы треугольника пересекаются в одной точке, достаточно рассмотреть две

    // Прямую, на которой лежит медиана, можно определить двумя точками - 
    // вершиной и серединой противолежащей стороны

    Point2D
    start1 = _array[0],
    start2 = _array[1],
    end1 = Point2D( (_array[1].x() + _array[2].x()) / 2, (_array[1].y() + _array[2].y()) / 2 ),
    end2 = Point2D( (_array[0].x() + _array[2].x()) / 2, (_array[0].y() + _array[2].y()) / 2 );

    return getIntersectionPoint(start1, end1, start2, end2);
}
Triangle::operator double() {
    Vector
    a(_array[0], _array[1]),
    b(_array[0], _array[2]);

    double cos = getCos(a, b);

    return 0.5 * a * b * (1 - cos * cos);
}

bool operator==(Triangle& a, Triangle& b) {
    // Треугольники равны, если равны все их стороны
    std::vector<double>
    sides1(3),
    sides2(3);
    for (int i = 0; i < 2; ++i) {
        for (int j = i + 1; j < 3; ++j) {
            sides1.push_back( Vector( a._array[i], a._array[j] ).getLength() );
            sides2.push_back( Vector( b._array[i], b._array[j] ).getLength() );
        }
    }

    sort(sides1.begin(), sides1.end());
    sort(sides2.begin(), sides2.end());

    for (int i = 0; i < 3; ++i) {
        if (sides1[i] != sides2[i])
            return false;
    }

    return true;
}

Triangle Triangle::create(std::vector<Point2D> points) {
    TriangleValidator validator;

    validator.validate(points);

    return Triangle(points);
}