#pragma once

#include <figure.h>

using Array = std::vector<Figure*>;

void printFigures(Array&);
double getTotalSquare(Array&);
Array& popIndex(Array&, int);