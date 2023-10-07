// Copyright 2023 Лебедько Платон
#include <bits/stdc++.h>
#include "octal.h"

using ll = int64_t;

char intToChar(int x) {
    return x + '0';
};
int charToInt(char c) {
    return c - '0';
};

size_t Octal::size() const {
    return _size;
}

int Octal::toInt() const {
    int num = 0;
    ll base = 1;
    for (int i = 0; i < _size; ++i) {
        num += charToInt(_array[i]) * base;
        base *= 8;
    }
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
        _array[i] = intToChar(num % 8);
        num /= 8;
    }
}
Octal::Octal(std::string num) {
    // std::cout << "Copy string constructor" << std::endl;

    if (num.size() == 0) {
        construct();
        return;
    }

    _size = num.size();
    _array = new unsigned char[_size];

    for (int i = 0; i < _size; ++i) {
        if (num[i] < '0' || num[i] > '7') {
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
    if (octal._size == 0) {
        out << "None";
        return out;
    }

    out << "0o";
    for (int i = octal._size - 1; i >= 0; --i)
        out << octal._array[i];
    
    return out;
}

bool Octal::operator < (const Octal& other) const {
    if (_size != other.size())
        return _size < other.size();
    
    for (int i = _size - 1; i >= 0; --i) {
        if (_array[i] != other._array[i]) {
            return _array[i] < other._array[i];
        }
    }

    return false;
}
bool Octal::operator > (const Octal& other) const {
    if (_size != other.size())
        return _size > other.size();

    for (int i = _size - 1; i >= 0; --i) {
        if (_array[i] != other._array[i]) {
            return _array[i] > other._array[i];
        }
    }

    return false;
}
bool Octal::operator == (const Octal& other) const {
    if (_size != other.size())
        return false;

    for (int i = _size - 1; i >= 0; --i) {
        if (_array[i] != other._array[i]) {
            return false;
        }
    }

    return true;
}

Octal Octal::operator + (const Octal& other) const {
    std::string num = "";

    char* greater = (char*)_array;
    char* smaller = (char*)other._array;
    int size = std::min(_size, other.size());
    if (_size < other.size())
        std::swap(greater, smaller);

    int carry = 0;
    for (int i = 0; i < size; ++i) {
        int c1 = charToInt(greater[i]),
        c2 = charToInt(smaller[i]);

        num += intToChar((c1 + c2 + carry) % 8);
        carry = (c1 + c2 + carry) / 8;
    }

    if (_size == other.size() && carry != 0) {
        num += intToChar(carry);
    }

    for (int i = size; i < std::max(_size, other.size()); ++i) {
        if (i == size && carry != 0) {
            num += intToChar( charToInt(greater[i]) + carry );
            continue;
        }

        num += greater[i];
    }

    std::string num_rev = "";
    for (int i = 0; i < num.size(); ++i)
        num_rev += num[num.size() - 1 - i];
    return Octal(num_rev);
}
Octal Octal::operator - (const Octal& other) const {
    if (*this < other) {
        throw std::logic_error("Overflow (negative number)");
    }

    std::string num = "";

    int carry = 0;
    for (int i = 0; i < other.size(); ++i) {
        int c1 = charToInt(_array[i]),
        c2 = charToInt(other._array[i]);

        if (c1 - carry >= c2) {
            num += intToChar(c1 - carry - c2);
            carry = 0;
        } else {
            c1 += 8;
            num += intToChar(c1 - carry - c2);
            carry = 1;
        }
    }

    for (int i = other.size(); i < _size; ++i) {
        if (i == other.size() && carry != 0) {
            num += intToChar( charToInt(_array[i]) - carry );
            continue;
        }

        num += _array[i];
    }

    std::string num_rev = "";
    for (int i = 0; i < num.size(); ++i)
        num_rev += num[num.size() - 1 - i];
    return Octal(num_rev);
}