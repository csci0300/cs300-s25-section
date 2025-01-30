#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

// Enum for aliasing game grid contents (X or O)
enum TTTSymbol{X, O};

// Struct to contstruct the game board out of (using an array of these structs)
struct TTTCell {
    // Indicates if a player filled in this cell (0 is empty, 1 is filled)
    int is_filled;
    // The symbol of the player that filled in this cell (if non-empty)
    enum TTTSymbol symbol;
};

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
int extract_numbers(char* input, int* row, int* col);
