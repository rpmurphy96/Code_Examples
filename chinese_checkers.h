//
// Created by Ryan Murphy on 2/23/19.
//

/*

  The required function prototypes and several variable names for this project were provided by Donald Yeung.

*/

#define BOARD_SIZE_X 25
#define BOARD_SIZE_Y 17

#define TRUE 1
#define FALSE 0

#define VALID_MOVE 1
#define INVALID_MOVE 2

/* definitions for pieces */
#define DA 0			/* disallowed */
#define RE 1			/* red */
#define GR 2			/* green */
#define EM 7			/* empty */

extern int the_board[BOARD_SIZE_Y][BOARD_SIZE_X];

/* Required Functions */
void print_board();
int check_neighbor(int x_from, int y_from, int x_to, int y_to);
int check_jump(int x_from, int y_from, int x_to, int y_to);
int check_move(int color, int x_from, int y_from, int x_to, int y_to);
int is_jumper(int x_from, int y_from, int x_to, int y_to);