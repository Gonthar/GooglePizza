//
// Created by Maciek on 23.02.2017.
//

#ifndef GOOGLEPIZZA_PIZZA_H
#define GOOGLEPIZZA_PIZZA_H


class Pizza {
public:
    static int rows, cols, elements, max;
    // Tomatoes are 0
    static int array[1000][1000];

    Pizza();
    int count_mushrooms(int, int, int, int) const;
};


#endif //GOOGLEPIZZA_PIZZA_H
