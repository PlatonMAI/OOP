#pragma once
#include <iostream>

template <typename T>
concept Number = std::is_default_constructible<T>::value || std::integral<T> || std::floating_point<T>;

template <Number T>
class Point2D {
    template <Number T_>
    friend std::ostream& operator<<(std::ostream&, const Point2D<T_>&);
    template <Number T_>
    friend std::istream& operator>>(std::istream&, Point2D<T_>&);
    
    template <Number T_>
    friend bool operator==(const Point2D<T_>&, const Point2D<T_>&);
    // friend bool operator<(const Point2D&, const Point2D&);
public:
    Point2D() = default;
    Point2D(T x, T y) : _x(x), _y(y) {}

    T x() const { return _x; }
    T y() const { return _y; }

    T& x() { return _x; }
    T& y() { return _y; }

protected:
    T _x;
    T _y;
};