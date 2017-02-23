//
// Created by Maciek on 23.02.2017.
//

#ifndef GOOGLEPIZZA_COVER_H
#define GOOGLEPIZZA_COVER_H


#include <vector>
#include "pizza.h"
#include "slice.h"

class Cover {
private:
    std::vector<Slice> _slices;
    int _score;
    int _token;

public:
    Cover(const Pizza&);
    Cover(const Cover&, const Cover&);

    bool operator<(const Cover&) const;

    void add(const Slice&);
    void randomize_token();

    int get_score() const;
    void print() const;
};


#endif //GOOGLEPIZZA_COVER_H
