#include <stdlib.h>
#include <stdio.h>

#define OPERAND_BUFFER_SIZE 10

/*
Students: The Expression struct should hold the two operands and
the operation (use a char for the operation)
*/


typedef struct {
    // hold the two operands and the operation
    unsigned int operand1;
    unsigned int operand2;
    char operation;


} Expression;

int bits_per_int() {
    return sizeof(unsigned int) * 8;
}

unsigned int parse_operand(char operand_str[]) {
    unsigned int operand;
    if (operand_str[0] == '0' && operand_str[1] == 'x') {
        scanf(&operand_str[2], "%x", &operand);
    } else if (operand_str[0] == '0') {
        scanf(&operand_str[1], "%o", &operand);
    } else {
        scanf(operand_str, "%u", &operand);
    }
    return operand;
}

void print_binary(unsigned int value) {
    // Students: Print a single number as a binary string
    int i;
    for (i = bits_per_int() - 1; i >= 0; i--) {
        printf("%d", (value >> i) & 1);
        if (i % 8 == 0) printf("'");
    }

}

void print_bit_operation_bin(Expression expression, unsigned int result) {
    /* 
    Students: Print the entire operation in binary including the result

    Bin:
    00000000'00000000'00000000'00001100
    00000000'00000000'00000000'00001111 ^
    -----------------------------------
    00000000'00000000'00000000'00000011
    */


    int i = 0;
    printf("%u %c %u = %u\n", expression.operand1, expression.operation, expression.operand2, result);
    printf("%u: ", expression.operand1);
    for (int i = 31; i >= 0; i--) {
        printf("%d", (expression.operand1 >> i) & 1);
        if (i % 8 == 0) printf("'");
    }
    printf("\n%u: ", expression.operand2);
    for (int i = 31; i >= 0; i--) {
        printf("%d", (expression.operand2 >> i) & 1);
        if (i % 8 == 0) printf("'");
    }
    printf("\n   ");
    for (int i = 0; i < 35; i++) {
        printf("-");
    }
    printf("\n%u: ", result);
    for (int i = 31; i >= 0; i--) {
        printf("%d", (result >> i) & 1);
        if (i % 8 == 0) printf("'");
    }
    printf("\n\n");


}

void print_bit_operation_hex(Expression expression, unsigned int result) {
    /* 
    Students: Print the entire operation in hex including the result

    Hex:
    0x0c ^ 0x0f = 0x03
    */
    int i = 0;
    printf("0x%08x %c 0x%08x = 0x%08x\n", expression.operand1, expression.operation, expression.operand2, result);
    printf("\nBin:\n");
    printf("   ");
    for (int i = 0; i < 35; i++) {
        printf("-");
    }
    printf("\n%u: ", expression.operand1);
    for (int i = 31; i >= 0; i--) {
        printf("%d", (expression.operand1 >> i) & 1);
        if (i % 8 == 0) printf("'");
    }
    printf("\n%u: ", expression.operand2);
    for (int i = 31; i >= 0; i--) {
        printf("%d", (expression.operand2 >> i) & 1);
        if (i % 8 == 0) printf("'");
    }
    printf("\n   ");
    for (int i = 0; i < 35; i++) {
        printf("-");
    }
    printf("\n%u: ", result);
    for (int i = 31; i >= 0; i--) {
        printf("%d", (result >> i) & 1);
        if (i % 8 == 0) printf("'");
    }
    printf("\n\n");


}

void print_bit_operation_dec(Expression expression, unsigned int result) {
    /* 
    Students: Print the entire operation in dec including the result

    Dec:
    12 ^ 15 = 3
    */
    int i = 0;
    printf("%u %c %u = %u\n", expression.operand1, expression.operation, expression.operand2, result);
    printf("\nBin:\n");
    printf("   ");
    for (int i = 0; i < 35; i++) {
        printf("-");
    }
    printf("\n%u: ", expression.operand1);
    for (int i = 31; i >= 0; i--) {
        printf("%d", (expression.operand1 >> i) & 1);
    }
    printf("\n%u: ", expression.operand2);
    for (int i = 31; i >= 0; i--) {
        printf("%d", (expression.operand2 >> i) & 1);
    }
    printf("\n   ");

    for (int i = 0; i < 35; i++) {
        printf("-");
    }
    printf("\n%u: ", result);
    for (int i = 31; i >= 0; i--) {
        printf("%d", (result >> i) & 1);
    }
    printf("\n\n");
}

unsigned int bit_operation(Expression expression) {
    // Students: Do the actual bit operation and return the result

    unsigned int result;
    switch(expression.operation) {
        case '&':
            result = expression.operand1 & expression.operand2;
            break;
        case '|':
            result = expression.operand1 | expression.operand2;
            break;
        case '^':
            result = expression.operand1 ^ expression.operand2;
            break;
        case '<':
            result = expression.operand1 << expression.operand2;
            break;
        case '>':
            result = expression.operand1 >> expression.operand2;
            break;
        default:
            result = 0;
    }
    return result;




}

int main(){
    char operand1_str[10];
    char operand2_str[10];
    char operation;

    unsigned int operand1, operand2;

    do {
        printf("Geben sie die Bit-Operation ein:\n");

        scanf("%s %c %s", operand1_str, &operation, operand2_str);
        
        operand1 = parse_operand(operand1_str);
        operand2 = parse_operand(operand2_str);

        // Students: Create an expression
        Expression expression = {operand1, operand2, operation};


        unsigned int result = bit_operation(expression);
        print_bit_operation_bin(expression, result);
        print_bit_operation_hex(expression, result);
        print_bit_operation_dec(expression, result);

        while(getchar() != '\n');
        printf("\nMoechten sie weiter machen oder abbrechen? [(n)ext|(q)uit] ");

    } while(getchar() == 'n');

    printf("Byebye..\n");
    return EXIT_SUCCESS;
}
