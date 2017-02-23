//
// Created by Maciek on 23.02.2017.
//

#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include "slice.h"

Slice::Slice(const Pizza& pizza) {
    int mushrooms = 0;
    int area = 0;

    while (mushrooms < pizza.elements || (area - mushrooms) < pizza.elements) {
        _x = rand() % (pizza.cols - + 1);
        _y = rand() % (pizza.rows - + 1);
        _width = std::max(floor(abs(rand() - rand()) * pizza.max + 1), pizza.cols - _y);
        // TODO zmienić na dążące do max, nie do min
        _height = std::max(floor(abs(rand() - rand()) * (pizza.max / _width) + 1), pizza.rows - _x);
        mushrooms = pizza.count_mushrooms(_x, _y, _x + _width, _y + _height);
        area = get_area();
    }
}

int Slice::get_area() const {
    return _width * _height;
}

bool Slice::overlap(const Slice& rhs) const {
    return 	_x < rhs._x + rhs._width &&
            _y < rhs._y + rhs._height &&
            _x + _width > rhs._x &&
            _y + _height > rhs._y;
}

void Slice::print() const {
    std::cout << _y << " " <<  _x << " " << _y + _height - 1 << " " << _x + _width - 1 << std::endl;
}