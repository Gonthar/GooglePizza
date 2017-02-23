//
// Created by Maciek on 23.02.2017.
//

#include <cmath>
#include <cstdlib>
#include <algorithm>
#include "solutions.h"

Solutions::Solutions(const Pizza& pizza, const int count) {
    _count = count;

    for (int i = 0; i < count; ++i) {
        _solutions.emplace_back(Cover(pizza));
    }
}

void Solutions::evaluate() {
    for (Cover& c : _solutions) {
        c.randomize_token();
    }
    std::sort(_solutions.begin(), _solutions.end());
}

void Solutions::evolve(const Pizza& pizza, const int crossover_prc, const int mutation_prc, const int elite_prc) {
    int crossover = floor(_count * crossover_prc / 100);
    int mutation = floor(_count * mutation_prc / 100);

    // Deleted and replaced
    for (int i = _count - crossover - mutation; i < _count - crossover; ++i) {
        _solutions[i] = Cover(pizza);
    }

    // Replaced by mutation
    for (int i = _count - mutation; i < _count; i++) {
        // Parents chosen at random
        _solutions[i] = Cover(_solutions[rand() % (_count - mutation)], _solutions[rand() % (_count - mutation)]);
    }
}

Cover Solutions::get_best() const {
    Cover best = _solutions[0];
    for (const Cover& s : _solutions) {
        if (s.get_score() > best.get_score()) {
            best = s;
        }
    }
    return best;
}
