#include "tictactoe.h"
#define BUFSIZE 24

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
int extract_numbers(char* input, int* row, int* col) {
  // Extract the first number (row)
  char* token = strtok(input, "x");
  // Error check for incomplete string before calling atoi
  if (token == NULL) {
    return -1;
  }
  int x = atoi(token);

  // Extract the second number (column)
  token = strtok(NULL, "x");
  // Error check for incomplete string before calling atoi
  if (token == NULL) {
    return -1;
  }
  int y = atoi(token);

  // Error check to make sure both numbers are non-negative
  if (x < 0 || y < 0) {
    return -1;
  } else {
    *row = x;
    *col = y;
    return 0;
  }
}

/* Function initialize_board
 *
 * Arguments:   dims, integer pointer to board dimensions (initialized by this
 * function) Returns:     TTTCell pointer to the allocated board region
 * (allocated on heap with malloc) Description: Extracts board dimensions from
 * STDIN. Mallocs a board with the inputted dimensions, initializes it, and
 * returns it to the user.
 */
struct TTTCell* initialize_board(int* dims) {
  // Extract how big the board should be
  while (*dims <= 0) {
    printf(
        "Enter dimensions for square board. For example, 3 is a 3 row, 3 col "
        "board.\n");

    // Extract dimensions for board
    char buffer[BUFSIZE];
    int bytes_read = read(STDIN_FILENO, buffer, BUFSIZE - 1); // Read input from terminal
    buffer[bytes_read] = '\0';

    dims = atoi(buffer);

    // Error check for nonexistant board dimensions
    if (dims <= 0) printf("Invalid board dimensions. Enter new dimensions.\n");
  }

  // Allocate space for the board (note the dereference for dims)
  struct TTTCell* board =
      (struct TTTCell*)malloc(sizeof(struct TTTCell) * (*dims));

  // Initialize the board here!
  for (int x = 0; x < dims; x++) {
    for (int y = 0; y < dims; y++) {
      board[(x * (*dims)) + y].symbol = X;
    }
  }

  // Note that the dimensions of the board are also returned since we update the
  // original reference
  return board;
}

/* Function update_board
 *
 * Arguments:   board, TTTCell pointer to the game board
 *              curr_player, TTTSymbol indicating current player (X or O)
 *              dims, dimensions of square game board
 * Returns:     None
 * Description: Extracts move location from STDIN and performs error bounds
 * checking. Updates board metadata with the inputted move
 */
void update_board(struct TTTCell* board, enum TTTSymbol curr_player, int dims) {
  int move_row = -1;
  int move_col = -1;
  int valid_move = -1;
  char buffer[BUFSIZE];

  // Extract move location
  while (valid_move == -1) {
    printf("Enter move location. For example, 0x0 is 0 row, 0 col.\n");
    int bytes_read = read(STDIN_FILENO, buffer, BUFSIZE - 1);
    buffer[bytes_read] = '\0';
    valid_move = extract_numbers(buffer, &move_row, &move_col);

    if (valid_move == -1) {
      printf("Invalid move location. Enter new move.\n");
    }
  }

  // Update the board
  board[(move_col * dims) + move_row].is_filled = 1;
  board[(move_col * dims) + move_row].symbol = curr_player;
}

/* Function main
 *
 * DO NOT EDIT OR CHANGE THIS FUNCTION
 *
 * Arguments:   None for this program
 * Returns:     Integer, indicating if error (non-zero) occurred
 * Description: Main function. Contains main game loop (implemented using
 * auxillary functions)
 */
int main() {
  // Set up and initialize the game board
  int dims = 0;
  struct TTTCell* board = initialize_board(&dims);

  display_board(board, dims);

  // Main game loop
  while (1) {
    // X player's turn
    printf("Player 1 (X), it's your turn.\n");
    update_board(board, X, dims);
    display_board(board, dims);

    // Determine if game ends with X victory
    if (check_win(board, X, dims)) {
      display_win(X);
      break;
    }

    // O player's turn
    printf("Player 2 (O), it's your turn.\n");
    update_board(board, O, dims);
    display_board(board, dims);

    // Determine if game ends with O victory
    if (check_win(board, O, dims)) {
      display_win(O);
      break;
    }
  }

  // Cleans up used heap memory
  free(board);

  return 0;
}

/* Function display_board
 *
 * DO NOT EDIT OR CHANGE THIS FUNCTION
 *
 * Arguments:   board, TTTCell pointer to the TTT board we want to draw. dims,
 * dimensions of the board Returns:     None Description: Draws the TTT board to
 * the screen using ASCII art
 */
void display_board(struct TTTCell* board, int dims) {
  // Print top row (contains column indices)
  printf(" ");
  for (int i = 0; i < dims; i++) {
    printf("  %d   ", i);
  }
  printf("\n");

  // Print each grid row
  for (int i = 0; i < dims; i++) {
    // Print the top part of this row
    printf(" ");
    for (int j = 0; j < dims; j++) {
      printf("     ");
      if (j == dims - 1)
        printf("\n");
      else
        printf("|");
    }

    // Print the middle part of this row (contains the row index)
    printf("%d", i);

    for (int j = 0; j < dims; j++) {
      printf("  ");
      // Lookup the grid value at this location
      if (board[(i * dims) + j].is_filled) {
        if (board[(i * dims) + j].symbol == X)
          printf("X");
        else if (board[(i * dims) + j].symbol == O)
          printf("O");
      } else
        // Blank row gets represented by a dash (-)
        printf("-");

      printf("  ");
      // Print either pipe or newline
      if (j == dims - 1)
        printf("\n");
      else
        printf("|");
    }

    // Print the bottom part of this row
    printf(" ");
    for (int j = 0; j < dims; j++) {
      // Separator or spaces
      if (i == dims - 1)
        printf("     ");
      else
        printf("_____");

      // Pipe or newline
      if (j == dims - 1)
        printf("\n");
      else
        printf("|");
    }
  }
}

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
int check_win(struct TTTCell* board, enum TTTSymbol curr_player, int dims) {
  // Check each row to see if this player won
  for (int i = 0; i < dims; i++) {
    for (int j = 0; j < dims; j++) {
      // Exit if this row doesn't result in a win
      int curr_pos = (i * dims) + j;
      if (!board[curr_pos].is_filled || board[curr_pos].symbol != curr_player)
        break;
      // If we've gotten to the end, this is a win
      if (j == dims - 1 && board[curr_pos].is_filled &&
          board[curr_pos].symbol == curr_player)
        return 1;
    }
  }

  // Check each col to see if this player won
  for (int j = 0; j < dims; j++) {
    for (int i = 0; i < dims; i++) {
      // Exit if this col doesn't result in a win
      int curr_pos = (i * dims) + j;
      if (!board[curr_pos].is_filled || board[curr_pos].symbol != curr_player)
        break;
      // If we've gotten to the end, this is a win
      if (i == dims - 1 && board[curr_pos].is_filled &&
          board[curr_pos].symbol == curr_player)
        return 1;
    }
  }

  // Check the diagonals (there are only two to check)
  // Top left diagonal
  for (int i = 0; i < dims; i++) {
    // Row and column each given by i
    int curr_pos = (i * dims) + i;

    // Check for early exit
    if (!board[curr_pos].is_filled || board[curr_pos].symbol != curr_player)
      break;

    // If we've gotten to the end, this is a win
    if (i == dims - 1 && board[curr_pos].is_filled &&
        board[curr_pos].symbol == curr_player)
      return 1;
  }

  // Top right diagonal
  for (int i = 0; i < dims; i++) {
    // Row given by i, column given by dims - 1 - i
    int curr_pos = (i * dims) + (dims - 1 - i);

    // Check for early exit
    if (!board[curr_pos].is_filled || board[curr_pos].symbol != curr_player)
      break;

    // If we've gotten to the end, this is a win
    if (i == dims - 1 && board[curr_pos].is_filled &&
        board[curr_pos].symbol == curr_player)
      return 1;
  }

  return 0;
}

/* Function display_win
 *
 * DO NOT EDIT OR CHANGE THIS FUNCTION
 *
 * Arguments:   curr_player, TTTSymbol enum indicating the current (winning)
 * player Returns:     None Description: Prints a message indicating the winning
 * player
 */
void display_win(enum TTTSymbol curr_player) {
  if (curr_player == X)
    printf("Congratulations Player 1 (X), you win!\n");
  else
    printf("Congratulations Player 2 (O), you win!\n");
}

