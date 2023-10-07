#pragma once
#include <bits/stdc++.h>

class Octal {
public:
    void construct();
    Octal();
    Octal(int num);
    Octal(std::string num);
    Octal(const std::initializer_list<unsigned char>& list);
    Octal(const Octal& other);
    Octal(Octal&& other) noexcept;

    Octal& operator = (const Octal& other);
    Octal& operator = (Octal&& other);

    friend std::ostream& operator << (std::ostream& out, const Octal& octal);
    size_t size() const;

    bool operator < (const Octal& other) const;
    bool operator > (const Octal& other) const;
    bool operator == (const Octal& other) const;

    Octal operator + (const Octal& other) const;
    Octal operator - (const Octal& other) const;

    int toInt() const;

    virtual ~Octal() noexcept;

private:
    size_t _size;
    unsigned char* _array;
};

char intToChar(int);
int charToInt(char);