//
// Created by Maciek on 23.02.2017.
//

#ifndef GOOGLEPIZZA_SOLUTIONS_H
#define GOOGLEPIZZA_SOLUTIONS_H


#include "pizza.h"
#include "cover.h"

class Solutions {
private:
    std::vector<Cover> _solutions;
    int _count;

public:
    Solutions(const Pizza&, const int);
    void evaluate();
    void evolve(const Pizza&, const int, const int, const int);
    Cover get_best() const;
};


#endif //GOOGLEPIZZA_SOLUTIONS_H
