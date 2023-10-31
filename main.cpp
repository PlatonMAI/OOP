// 17. Треугольник Квадрат Прямоугольник

#include <bits/stdc++.h>

#include <figure.h>
#include <triangle.h>
#include <square.h>
#include <rectangle.h>
#include <array.h>

using namespace std;

int main() {
    vector<Point2D> tri{{0, 0}, {1, 0}, {0, 1}};
    vector<Point2D> tri_{{1, 1}, {1, 0}, {0, 1}};
    vector<Point2D> rect{{0, 0}, {2, 0}, {2, 1}, {0, 1}};
    vector<Point2D> rect_{{2, 0}, {0, 0}, {2, 1}, {0, 1}};
    vector<Point2D> sq{{0, 0}, {1, 0}, {1, 1}, {0, 1}};

    // Rectangle r = Rectangle::create(rect);
    
    Triangle t(tri);
    cout << t << endl;
    Rectangle r(rect_);
    cout << r << endl;
    Square s(sq);
    cout << s << endl;

    Array array{&t, &r, &s};
    printFigures(array);
    cout << getTotalSquare(array) << endl;
    popIndex(array, 1);
    printFigures(array);

    // Triangle t1(t);
    // cout << t1 << endl;
    // Triangle t2(move(t));
    // cout << t2 << endl;
    // t = t1;
    // cout << t << endl;

    // vector<Point2D> tri1{{0, 0}, {1, 0}, {0, 1}};
    // vector<Point2D> tri2{{0, 0}, {-1, 0}, {0, 1}};
    // vector<Point2D> tri3{{0, 0}, {-1, 0}, {0, -1}};
    // vector<Point2D> tri4{{0, 0}, {1, 0}, {0, -1}};

    // Triangle t1 = Triangle::create(tri1);
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