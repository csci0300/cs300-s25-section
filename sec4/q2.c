#include <stdio.h>
#include <stdlib.h>

int add(int a, int b) {
    int result = a + b;
    // *** B ***
    return result;
}

int main() {
    int result;
    long a = 7;
    short b = 12;
    // *** A ***

    result = add(a, b);
    // *** C ***
    printf("Result of adding %ld and %d is %d.\n", a, b, result);
    // *** D ***

    return 0;
}
