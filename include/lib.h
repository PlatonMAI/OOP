#pragma once
#include <bits/stdc++.h>

class Octal {
public:
    void construct();
    Octal();
    Octal(int num);
    Octal(const char* num);
    Octal(const std::initializer_list<unsigned char>& list);
    Octal(const Octal& other);
    Octal(Octal&& other) noexcept;

    Octal& operator = (const Octal& other);
    Octal& operator = (Octal&& other);

    std::ostream& print(std::ostream& out) const;
    size_t size() const;

    bool less(const Octal& other) const; // true if other >
    bool greater(const Octal& other) const; // true if other <
    bool equals(const Octal& other) const;

    Octal plus(const Octal& other) const;
    Octal minus(const Octal& other) const; // this - other

    int toInt() const;

    virtual ~Octal() noexcept;

private:
    size_t _size;
    unsigned char* _array;
};

std::ostream& operator << (std::ostream& out, const Octal& octal);
bool operator < (const Octal& a, const Octal& b);
bool operator > (const Octal& a, const Octal& b);
bool operator == (const Octal& a, const Octal& b);

Octal operator + (const Octal& a, const Octal& b);
Octal operator - (const Octal& a, const Octal& b);