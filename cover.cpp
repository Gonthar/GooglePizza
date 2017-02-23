//
// Created by Maciek on 23.02.2017.
//

#include <algorithm>
#include <iostream>
#include "cover.h"

Cover::Cover(const Pizza& pizza) {
    _score = 0;
    add(Slice(pizza));
}

Cover::Cover(const Cover& a, const Cover& b) {
    _score = 0;
    std::vector<Slice> merged;

    merged.insert(merged.end(), a._slices.begin(), a._slices.end());
    merged.insert(merged.end(), b._slices.begin(), b._slices.end());

    random_shuffle(merged.begin(), merged.end());

    for (const Slice& m : merged) {
        bool collision = false;
        for (Slice &s : _slices) {
            collision |= s.overlap(m);
            if (collision) {
                break;
            }
        }

        if (!collision) {
            add(m);
        }
    }
}

void Cover::add(const Slice& s) {
    _slices.emplace_back(s);
    _score += s.get_area();
}

bool Cover::operator<(const Cover& rhs) const {
    return _token > rhs._token;
}

double random_double(double lower_bound, double upper_bound) {
    double rd = (double)rand() / RAND_MAX;
    return lower_bound + rd * (upper_bound - lower_bound);
}

void Cover::randomize_token() {
    double margin = (double)_score / 4.0;
    _token = random_double(_score - margin, _score + margin);
}

void Cover::print() const {
    std::cout << _slices.size() << std::endl;
    for (const Slice& s : _slices) {
        s.print();
    }
}