#include <stdio.h>

void add_and_print1(int num) {
    num += 5;
    printf("The number is: %d\n", num);
}

void add_and_print2(int* num) {
    *num += 2;
    printf("The number is: %d\n", *num);
}

int main() {
    int cool_num = 10;

    add_and_print1(cool_num);

    add_and_print2(&cool_num);

    printf("%d\n", cool_num);

    return 0;
}
