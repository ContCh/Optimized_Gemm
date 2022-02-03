#include <iostream>
#include "clocks.h"



int main() {
    clock_start();

    int number = -25000;
    for (int i = 0; i < 100000; i++) {
        number += 1;
    }

    int span = clock_end(MICROSEC);
    std::cout << "result: " << number << " , cost " << span << " us.\n";
}
