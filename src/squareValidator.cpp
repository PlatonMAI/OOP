#include <squareValidator.h>
#include <square.h>

bool SquareValidator::validate(std::vector<Point2D>& points) {
    // Квадрат - это прямоугольник с равными сторонами
    // На прямоугольник проверять умеем, проверим на равенство сторон

    RectangleValidator::validate(points);

    std::vector<double> sides;
    std::vector<Point2D> new_points = sortPoints(points);
    for (int i = 0; i < 4; i += 2) {
        for (int j = 1; j < 4; j += 2) {
            sides.push_back( Vector(new_points[i], new_points[j]).getLength() );
        }
    }

    std::sort(sides.begin(), sides.end());
    if (sides[0] != sides[3]) {
        throw validator_error("Введенные точки не образуют квадрат:\nстороны не равны");
    }

    return true;
}
bool SquareValidator::validate(Point2D& a, Point2D& c) {
    // Проверим сначала, можем ли построить прямоугольник
    // Затем выгоднее просто восстановить точки
    // и скормить стандартному валидатору

    RectangleValidator::validate(a, c);

    std::vector<Point2D> tmp( recoverPoints(a, c) );
    validate(tmp);

    return true;
}