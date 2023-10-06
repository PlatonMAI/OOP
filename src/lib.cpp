// Copyright 2023 Лебедько Платон
#include <bits/stdc++.h>
#include "lib.h"

size_t Octal::size() const {
    return _size;
}

int Octal::toInt() const {
    int num = 0;
    for (int i = 0; i < _size; ++i)
        num += (_array[i] - 48) * std::pow(8, i);
    return num;
}

void Octal::construct() {
    _size = 1;
    _array = new unsigned char[1];
    _array[0] = '0';
}
Octal::Octal() {
    construct();
}
Octal::Octal(int num) {
    if (num == 0) {
        construct();
        return;
    }

    _size = static_cast<size_t>(log2(num) / 3) + 1; // log8(n) = 1/3*log2(n)
    _array = new unsigned char[_size];

    for (int i = 0; num != 0; ++i) {
        _array[i] = (num % 8) + 48;
        num /= 8;
    }
}
Octal::Octal(const char* num) {
    // std::cout << "Copy string constructor" << std::endl;

    if (strlen(num) == 0) {
        construct();
        return;
    }

    _size = strlen(num);
    _array = new unsigned char[_size];

    for (int i = 0; i < _size; ++i) {
        if (num[i] < '0' || num[i] > '7') { // '0' - 48, '7' - 55
            throw std::logic_error("invalid literal for int with base 8");
        }
        _array[_size - 1 - i] = num[i];
    }
}
Octal::Octal(const std::initializer_list<unsigned char>& list) { // Инициализация списком
    if (list.size() == 0) {
        construct();
        return;
    }

    _size = list.size();
    _array = new unsigned char[_size];

    int i = 0;
    for (char c : list)
        _array[i++] = c;
}
Octal::Octal(const Octal& other) { // Конструктор копирования
    // std::cout << "Copy constructor" << std::endl;

    _size = other.size();
    _array = new unsigned char[_size];

    for (int i = 0; i < _size; ++i)
        _array[i] = other._array[i];
}
Octal::Octal(Octal&& other) noexcept { // Конструктор перемещения
    // std::cout << "Move constructor" << std::endl;

    _size = other.size();
    _array = other._array;

    other._size = 0;
    other._array = nullptr;
}

Octal& Octal::operator = (const Octal& other) {
    _size = other.size();
    if (_array != nullptr)
        delete[] _array;
    _array = new unsigned char[_size];

    for (int i = 0; i < _size; ++i)
        _array[i] = other._array[i];

    return *this;    
}
Octal& Octal::operator = (Octal&& other) {
    _size = other.size();
    _array = other._array;

    other._size = 0;
    other._array = nullptr;

    return *this;    
}

Octal::~Octal() {
    if (_size > 0) {
        delete[] _array;
        _array = nullptr;
    }
}

std::ostream& operator << (std::ostream& out, const Octal& octal) {
    return octal.print(out);
}
std::ostream& Octal::print(std::ostream& out) const {
    if (_size == 0)
        out << "None";
    else {
        out << "0o";
        for (int i = _size - 1; i >= 0; --i)
            out << _array[i];
    }
    return out;
}

bool operator < (const Octal& a, const Octal& b) {
    return a.less(b);
}
bool Octal::less(const Octal& other) const {
    if (_size != other.size()) {
        return _size < other.size();
    } else {
        for (int i = _size - 1; i >= 0; --i) {
            if (_array[i] != other._array[i]) {
                return _array[i] < other._array[i];
            }
        }
    }
    return false;
}
bool operator > (const Octal& a, const Octal& b) {
    return a.greater(b);
}
bool Octal::greater(const Octal& other) const {
    if (_size != other.size()) {
        return _size > other.size();
    } else {
        for (int i = _size - 1; i >= 0; --i) {
            if (_array[i] != other._array[i]) {
                return _array[i] > other._array[i];
            }
        }
    }
    return false;
}
bool operator == (const Octal& a, const Octal& b) {
    return a.equals(b);
}
bool Octal::equals(const Octal& other) const {
    if (_size != other.size()) {
        return false;
    } else {
        for (int i = _size - 1; i >= 0; --i) {
            if (_array[i] != other._array[i]) {
                return false;
            }
        }
    }
    return true;
}

Octal operator + (const Octal& a, const Octal& b) {
    return a.plus(b);
}
Octal Octal::plus(const Octal& other) const {
    int num = 0;

    char* greater = (char*)_array;
    char* smaller = (char*)other._array;
    int size = std::min(_size, other.size());
    if (_size < other.size())
        std::swap(greater, smaller);

    int carry = 0;
    for (int i = 0; i < size; ++i) {
        int c1 = greater[i] - 48,
        c2 = smaller[i] - 48;

        num += ((c1 + c2 + carry) % 8) * std::pow(8, i);
        carry = (c1 + c2 + carry) / 8;
    }

    if (_size == other.size() && carry != 0) {
        num += carry * std::pow(8, _size);
    }

    for (int i = size; i < std::max(_size, other.size()); ++i) {
        if (i == size && carry != 0) {
            num += ((greater[i] - 48) + carry) * std::pow(8, i);
            continue;
        }

        num += (greater[i] - 48) * std::pow(8, i);
    }

    return Octal(num);
}

Octal operator - (const Octal& a, const Octal& b) {
    return a.minus(b);
}
Octal Octal::minus(const Octal& other) const {
    if (*this < other) {
        throw std::logic_error("Overflow (negative number)");
    }

    int num = 0;

    int carry = 0;
    for (int i = 0; i < other.size(); ++i) {
        int c1 = _array[i] - 48,
        c2 = other._array[i] - 48;

        if (c1 - carry >= c2) {
            num += (c1 - carry - c2) * pow(8, i);
            carry = 0;
        } else {
            c1 += 8;
            num += (c1 - carry - c2) * pow(8, i);
            carry = 1;
        }
    }

    for (int i = other.size(); i < _size; ++i) {
        if (i == other.size() && carry != 0) {
            num += ((_array[i] - 48) - carry) * std::pow(8, i);
            continue;
        }

        num += (_array[i] - 48) * std::pow(8, i);
    }

    return Octal(num);
}