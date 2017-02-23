//
// Created by Maciek on 23.02.2017.
//

#ifndef GOOGLEPIZZA_SLICE_H
#define GOOGLEPIZZA_SLICE_H


#include "pizza.h"

class Slice {
private:
    // x & y: top left corner
    int _x, _y, _width,_height;

public:
    Slice(const Pizza&);
    Slice(const Pizza&, const int, const int, const int, const int);
    int get_area() const;
    bool overlap(const Slice& rhs) const;
    void print() const;
};


#endif //GOOGLEPIZZA_SLICE_H
