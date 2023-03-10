//
// Created by ngaem on 10/03/2023.
//
#include <stdlib.h>
#include <stdio.h>

int main(){
    int x = 3;
    int y = 4;
    printf("x: %d; y: %d\n", x, y);

    // Swap a and b
    x = x ^ y; // x now becomes 12 (1100)
    printf("1. x: %d; y: %d\n", x, y);
    y = x ^ y; // y becomes 10 (1010)
    printf("2. x: %d; y: %d\n", x, y);
    x = x ^ y; // x becomes 5 (0101)


    printf("x: %d; y: %d\n", x, y);
    return EXIT_SUCCESS;
}