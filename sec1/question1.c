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

    char *the_string = "I love CS300!";
    char fav_char = '!';
    dereference_and_set(&fav_char, '?');

    char *smaller_string = "";
    size_t string_end = strlen(the_string);

    for (size_t i = 0; i <= string_end; i++)
    {
        smaller_string = the_string + i;
        printf("%s\n", smaller_string);
    }

    dereference_and_set(smaller_string, '!');

    return 0;
}
