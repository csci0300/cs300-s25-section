#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Enum for aliasing game grid contents (X or O)
enum TTTSymbol { X, O };

// Struct to contstruct the game board out of (using an array of these structs)
struct TTTCell {
  // Indicates if a player filled in this cell (0 is empty, 1 is filled)
  int is_filled;
  // The symbol of the player that filled in this cell (if non-empty)
  enum TTTSymbol symbol;
};

/* Function extract_numbers
 *
 * Arguments:   input, character pointer corresponding to null-terminated input
 * string to extract numbers from input should be in the format of AxB, where A
 * and B are numbers corresponding to row and col, respectively row and col,
 * integer pointers that allow for accessing both the inputted row and col
 * Returns:     integer, indicating if inputted move was valid
 *              (row and col could be read and are both non-negative)
 * Description: Extracts two numbers from STDIN based on user input.
 *              Reads input from user indicating a row and column for move (in
 * the format RowxCol) Errors if both numbers are not inputted in this form or
 * if either is negative
 */
int extract_numbers(char* input, int* row, int* col);

/* Function initialize_board
 *
 * Arguments:   dims, integer pointer to board dimensions (initialized by this
 * function) Returns:     TTTCell pointer to the allocated board region
 * (allocated on heap with malloc) Description: Extracts board dimensions from
 * STDIN. Mallocs a board with the inputted dimensions, initializes it, and
 * returns it to the user.
 */
struct TTTCell* initialize_board(int* dims);

/* Function update_board
 *
 * Arguments:   board, TTTCell pointer to the game board
 *              curr_player, TTTSymbol indicating current player (X or O)
 *              dims, dimensions of square game board
 * Returns:     None
 * Description: Extracts move location from STDIN and performs error bounds
 * checking. Updates board metadata with the inputted move
 */
void update_board(struct TTTCell* board, enum TTTSymbol curr_player, int dim);

/* Function display_board
 *
 * DO NOT EDIT OR CHANGE THIS FUNCTION
 *
 * Arguments:   board, TTTCell pointer to the TTT board we want to draw. dims,
 * dimensions of the board Returns:     None Description: Draws the TTT board to
 * the screen using ASCII art
 */
void display_board(struct TTTCell* board, int dims);

/* Function check_win
 *
 * DO NOT EDIT OR CHANGE THIS FUNCTION
 *
 * Arguments:   board, TTTCell pointer to the game board
 *              curr_player, TTTSymbol indicating current player (X or O)
 *              dims, dimensions of square game board
 * Returns:     int, indicating if the curr_player has won (1) or not won (0)
 * Description: Determines if the current player has won by placing their symbol
 *              on all cells in a single row, column, or diagonal
 */
int check_win(struct TTTCell* board, enum TTTSymbol curr_player, int dim);

/* Function display_win
 *
 * DO NOT EDIT OR CHANGE THIS FUNCTION
 *
 * Arguments:   curr_player, TTTSymbol enum indicating the current (winning)
 * player Returns:     None Description: Prints a message indicating the winning
 * player
 */
void display_win(enum TTTSymbol curr_player);

