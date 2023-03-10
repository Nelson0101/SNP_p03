//
// Created by ngaem on 10/03/2023.
//
#include <stdlib.h>
#include <stdio.h>

int main(){
    char word[8] = "IchMagHu";
    char *wordptr = &word[0];

    while(wordptr < &word[7]) {
        printf("UPPERCASE: %c\n", *wordptr & '_'); // converts the char into uppercase regardless of the current casing
        printf("LOWERCASE: %c\n", *wordptr | ' '); // converts the char into lowercase regardless of the current casing
        wordptr++;
    }

    return EXIT_SUCCESS;
}//
// Created by ngaem on 10/03/2023.
//
