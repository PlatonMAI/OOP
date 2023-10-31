#include <rectangle.h>
#include <rectangleValidator.h>

std::vector<Point2D> recoverPoints(Point2D& a, Point2D& c) {
    Point2D
    b(a.x(), c.y()),
    d(c.x(), a.y());

    return std::vector<Point2D>{a, b, c, d};
}

// Хотим, чтобы первая и третья, а также вторая и четвертая точки в массиве были противоположными вершинами
std::vector<Point2D> sortPoints(std::vector<Point2D>& points) {
    // Для этого зафиксируем точку, найдем расстояния от нее до всех остальных трех.
    // Точка, до которой будет наибольшее расстояние - и есть искомая противоположная вершина
    
    std::vector<Point2D> new_points(4);
    new_points[0] = points[0];
    double max_dist = 0;
    int index = -1;
    for (int i = 0; i < 3; ++i) {
        double dist = Vector(points[0], points[i + 1]).getLength();

        if (dist > max_dist) {
            max_dist = dist;
            index = i + 1;
        }
    }

    new_points[2] = points[index];
    new_points[1] = points[ (index - 1) == 0 ? 3 : (index - 1) ];
    new_points[3] = points[ (index + 1) == 4 ? 1 : (index + 1) ];

    // std::cout << "Посортил: ";
    // for (int i = 0; i < 4; ++i)
    //     std::cout << new_points[i] << " ";
    // std::cout << std::endl;

    return new_points;
}

Rectangle::Rectangle(std::vector<Point2D>& points) {
    points = sortPoints(points);

    // Можно ли как-то вызвать конструктор Figure с отсортированным points?
    constructor(points);
}
Rectangle::Rectangle(Point2D& a, Point2D& c) {
    std::vector<Point2D> tmp( recoverPoints(a, c) );
    // Тут, очевидно, мы гарантируем, что вектор отсортирован правильно
    constructor(tmp);
}
Rectangle::Rectangle(const Rectangle& other) {
    std::cout << "Конструктор копирования прямоугольника" << std::endl;
    std::vector<Point2D> points = other.getPoints();

    constructor(points);
}

Rectangle& Rectangle::operator=(const Rectangle& other) {
    std::cout << "Оператор копирующего присваивания прямоугольника " << std::endl;
    std::vector<Point2D> points = other.getPoints();

    builder(points);

    return *this;
}

Point2D Rectangle::get_center() {
    // Центр прямоугольника - точка пересечения его диагоналей
    // По построению - первая и третья, а также вторая и четвертая точки - противоположные вершины

    return getIntersectionPoint(_array[0], _array[2], _array[1], _array[3]);
}
Rectangle::operator double() {
    // Площадь - приятно
    Vector
    a(_array[0], _array[1]),
    b(_array[0], _array[3]);

    return a * b;
}

Rectangle Rectangle::create(std::vector<Point2D> points) {
    RectangleValidator validator;

    validator.validate(points);

    return Rectangle(points);
}
Rectangle Rectangle::create(Point2D& a, Point2D& c) {
    RectangleValidator validator;

    validator.validate(a, c);

    return Rectangle(a, c);
}