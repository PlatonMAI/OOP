#include <square.h>
#include <squareValidator.h>

Square Square::create(std::vector<Point2D> points) {
    SquareValidator validator;

    validator.validate(points);

    return Square(points);
}
Square Square::create(Point2D& a, Point2D& c) {
    SquareValidator validator;

    validator.validate(a, c);

    return Square(a, c);
}