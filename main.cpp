#include <ctime>
#include <cstdlib>

#include "pizza.h"
#include "solutions.h"


int main() {
    srand(time(NULL));
    clock_t start = clock();
    Pizza pizza;
    Solutions solutions(pizza, 7500);

    while((double)(clock() - start) / CLOCKS_PER_SEC < 60) {
        // ordering
        solutions.evaluate();
        // next gen
        // Arg 2: crossover, 3: mutation, 4: elite
        solutions.evolve(pizza, 25, 15, 5);
    }

    Cover best = solutions.get_best();
    best.print();

    return 0;
}