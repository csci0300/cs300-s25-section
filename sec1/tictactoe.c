#include "tictactoe.h"
#define BUFSIZE 24

/* Function extract_numbers
 * 
 * Arguments:   input, character pointer corresponding to null-terminated input string to extract numbers from
 *              input should be in the format of AxB, where A and B are numbers corresponding to row and col, respectively
 *              row and col, integer pointers that allow for accessing both the inputted row and col
 * Returns:     integer, indicating if inputted move was valid
 *              (row and col could be read and are both non-negative)
 * Description: Extracts two numbers from STDIN based on user input.
 *              Reads input from user indicating a row and column for move (in the format RowxCol)
 *              Errors if both numbers are not inputted in this form or if either is negative
 */
int extract_numbers(char *input, int *row, int *col) {
    // BUG 1: References are immeadiatley set to 0 (NULL) when they should not be
    // Will cause a segmentation fault when trying to update variables later
    // Initialize variables
    // row = 0;
    // col = 0;
    
    // Extract the first number (row)
    char *token = strtok(input, "x");
    // Error check for incomplete string before calling atoi
    if (token == NULL)
        return -1;
    int x = atoi(token);

    // Extract the second number (column)
    token = strtok(NULL, "x");
    // Error check for incomplete string before calling atoi
    if (token == NULL)
        return -1;
    int y = atoi(token);

    // Error check to make sure both numbers are non-negative
    if (x < 0 || y < 0) {
        return -1;
    }
    else {
        // BUG 2: row and col pointers not being dereferenced and being updated directly
        // Will cause a segmentation fault
        *row = x;
        *col = y;
        return 0;
    }
}

/* Function main
 * 
 * DO NOT CHANGE OR EDIT THIS FUNCTION
 * 
 * Arguments:   None for this program
 * Returns:     Integer, indicating if error (non-zero) occurred
 * Description: Main function. Contains main game loop (implemented using auxillary functions)
 */
int main() {
    int row = -1;
    int col = -1;
    char buffer[BUFSIZE];

    printf("Enter some numbers (like \"3x3\") to test if the correct numbers were extracted.\n");
    buffer[read(STDIN_FILENO, buffer, BUFSIZE - 1)] = '\0';
    extract_numbers(buffer, &row, &col);
    printf("The extracted numbers were %d and %d.\n", row, col);
    printf("The extracted numbers should not be negative!\n");

    return 0;
}