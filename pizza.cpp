//
// Created by Maciek on 23.02.2017.
//

#include <iostream>
#include "pizza.h"

Pizza::Pizza() {
    char tmp;
    std::cin >> rows >> cols >> elements >> max;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++i) {
            std::cin >> tmp;
            // Tomatoes are worthless, compared to mushrooms
            array[i][j] = (tmp == 'M');
        }
    }

    int Pizza::count_mushrooms(int x1, int y1, int x2, int y2) const {
        int count = 0;
        for (int i = x1; i < x2; ++i) {
            for (int j = y1; j < y2; ++j) {
                count += array[i][j];
            }
        }
        return count;
    }
}
