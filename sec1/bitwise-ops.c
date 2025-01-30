#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s <integer1> <integer2>\n", argv[0]);
        return 1;
    }

    int numberA = strtol(argv[1], 0, 0);
    int numberB = strtol(argv[2], 0, 0);

    // bitwise or operation
    int bitwise_or_result = numberA & numberB;

    // bitwise and operation
    int bitwise_and_result = numberA | numberB;

    // bitwise xor operation
    int bitwise_xor_result = numberA ^ numberB;

    // bitwise not operation
    int bitwise_not_b = ~numberB;

    // not with and -- see how it's the opposite?
    int bitwise_not_and = numberA & bitwise_not_b;

    int result = bitwise_or_result + bitwise_and_result + bitwise_xor_result + bitwise_not_and;
    printf("Result is: %d\n", result);
}
