//
// Created by ngaem on 10/03/2023.
//
#include <stdio.h>
#include <stdlib.h>

int main(){
    int a = 33; // any positive number

    if(a > 0 && (a & (a - 1)) == 0){
        printf("%d is a power of 2", a);
    } else {
        printf("%d is not a power of 2", a);
    }

    return EXIT_SUCCESS;
}