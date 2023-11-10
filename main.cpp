// 17. Треугольник Квадрат Прямоугольник

#include <bits/stdc++.h>

#include <../src/figure.cpp>
#include <../src/triangle.cpp>
#include <../src/square.cpp>
#include <../src/rectangle.cpp>
#include <../src/array.cpp>

using namespace std;

// using Array = vector<Figure<double>*>;

int main() {
    vector<Point2D<double>> tri{{0, 0}, {1, 0}, {0, 1}};
    vector<Point2D<double>> tri_{{1, 1}, {1, 0}, {0, 1}};
    vector<Point2D<double>> rect{{0, 0}, {2, 0}, {2, 1}, {0, 1}};
    vector<Point2D<double>> rect_{{2, 0}, {0, 0}, {2, 1}, {0, 1}};
    vector<Point2D<double>> sq{{0, 0}, {1, 0}, {1, 1}, {0, 1}};

    // Rectangle r = Rectangle::create(rect);
    
    Triangle<double> t = Triangle<double>::create(tri);
    cout << t << endl;
    Rectangle<double> r = Rectangle<double>::create(rect_);
    cout << r << endl;
    Square<double> s = Square<double>::create(sq);
    cout << s << endl;

    // Array<double> array({shared_ptr<Figure<double>>(&t), shared_ptr<Figure<double>>(&r), shared_ptr<Figure<double>>(&s)});
    shared_ptr<Figure<double>> tp = make_shared<Triangle<double>>(tri);
    shared_ptr<Figure<double>> rp = make_shared<Rectangle<double>>(rect_);
    shared_ptr<Figure<double>> sp = make_shared<Square<double>>(sq);
    Array<double> array{{tp, rp, sp}};
    array.printFigures();
    cout << array.getTotalSquare() << endl;
    array.popIndex(1);
    array.printFigures();

    // Triangle t1(t);
    // cout << t1 << endl;
    // Triangle t2(move(t));
    // cout << t2 << endl;
    // t = t1;
    // cout << t << endl;

    // vector<Point2D<double>> tri1{{0, 0}, {1, 0}, {0, 1}};
    // vector<Point2D> tri2{{0, 0}, {-1, 0}, {0, 1}};
    // vector<Point2D> tri3{{0, 0}, {-1, 0}, {0, -1}};
    // vector<Point2D> tri4{{0, 0}, {1, 0}, {0, -1}};

    // Triangle<double> t1 = Triangle<double>::create(tri1);
    // Triangle t2 = Triangle::create(tri2);
    // Triangle t3 = Triangle::create(tri3);
    // Triangle t4 = Triangle::create(tri4);
    // cout << t1.get_center() << " " << t1 + 0.0 << endl;
    // cout << t2.get_center() << " " << t2 + 0.0 << endl;
    // cout << t3.get_center() << " " << t3 + 0.0 << endl;
    // cout << t4.get_center() << " " << t4 + 0.0 << endl;

    // Rectangle r1(r);
    // cout << r1 << endl;

    // Square s1(move(s));
    // cout << s1 << endl;

    // Square s1 = Square::create(sq);
    // cout << s1 << endl;

    // Triangle t = Triangle::create({Point2D{0, 0}, Point2D{0, 1}, Point2D{1, 0}});
    // Rectangle t = Rectangle::create({{0, 0}, {0, 1}, {1, 0}});
    // Square t = Square::create({{0, 0}, {0, 1}, {1, 0}});
}