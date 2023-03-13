#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

typedef struct Graphic Graphic;

/*
Students: Create a new type "Graphic" that can store:
- shape (OVAL, RECTANGLE) -> create a new enum for this type
- size
- color
*/
enum Shape {OVAL, RECTANGLE};

struct Graphic {
    enum Shape shape;
    unsigned int size;
    char *color;
};


void paint(Graphic graphic) {
    double radius = graphic.size / 2.0;
    int i,j;

    for (i = 0; i <= 2 * radius; i++){
        for (j = 0; j <= 2 * radius; j++){
            switch(graphic.shape) {
                case RECTANGLE: printf("%s*" RESET, graphic.color); break;
                case OVAL: {
                    double distance = sqrt((i - radius) * (i - radius) + (j - radius) * (j - radius));
                    if (distance > radius - 0.5 && distance < radius + 0.5) {
                        printf("%s*" RESET, graphic.color);
                    } else {
                        printf(" ");
                    }
                } break;

            }
        }
        printf("\n");
    }
}

int main() {
    int input;
    Graphic graphic;

    do {
        printf("Geben Sie die gewuenschte Form an [OVAL=0 | RECTANGLE=1]:");
        scanf("%d", &input);
        // Students: store the input in graphic
        graphic.shape = input == 0 ? OVAL : RECTANGLE;

        printf("Geben Sie die gewuenschte Grösse an:");
        scanf("%u", &input);
        // Students: store the input in graphic
        graphic.size = input;

        printf("Geben Sie die gewuenschte Farbe an [RED=0 | GREEN=1 | YELLOW=2]:");
        scanf("%d", &input);
        // Students: store the input in graphic
        graphic.color = input == 0 ? RED : input == 1 ? GRN : YEL;

        paint(graphic);

        while(getchar() != '\n'); // empty buffer
        printf("\nMoechten sie weiter machen oder abbrechen? [(n)ext|(q)uit] ");
    } while(getchar() == 'n');

    printf("Byebye..\n");
    return EXIT_SUCCESS;
}

