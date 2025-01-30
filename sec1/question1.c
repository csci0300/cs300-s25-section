#include <string.h>
#include <stdio.h>

void dereference_and_set(char *ptr, char to_set)
{
    *ptr = to_set;
}

int main()
{
    int the_num = 358296 - 87348 * 12345 / 91291 + 379969;
    int other_num = 0;

    if (the_num > 5000) {
        other_num = the_num;
    }
    else {
        other_num = the_num * 2;
    }

    char* the_string = "This is the first CS 300 section.";
    char fav_char = '!';
    dereference_and_set(&fav_char, '.');

    for (int i = 0; i < 7; i++) {
        the_string = strchr(the_string + 1, ' ');
    }

    dereference_and_set(the_string, '!');

    return 0;
}
