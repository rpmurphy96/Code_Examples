//
// Created by Ryan Murphy on 2/23/19.
//

/*

  The required function prototypes and several variable names for this project were provided by Donald Yeung.

*/


#include <stdio.h>
#include "chinese_checkers.h"



int the_board[BOARD_SIZE_Y][BOARD_SIZE_X] = {{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
                                             {0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0},
                                             {0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0},
                                             {0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0},
                                             {7,0,7,0,7,0,7,0,7,0,7,0,7,0,7,0,7,0,7,0,7,0,7,0,7},
                                             {0,7,0,7,0,7,0,7,0,7,0,7,0,7,0,7,0,7,0,7,0,7,0,7,0},
                                             {0,0,7,0,7,0,7,0,7,0,7,0,7,0,7,0,7,0,7,0,7,0,7,0,0},
                                             {0,0,0,7,0,7,0,7,0,7,0,7,0,7,0,7,0,7,0,7,0,7,0,0,0},
                                             {0,0,0,0,7,0,7,0,7,0,7,0,7,0,7,0,7,0,7,0,7,0,0,0,0},
                                             {0,0,0,7,0,7,0,7,0,7,0,7,0,7,0,7,0,7,0,7,0,7,0,0,0},
                                             {0,0,7,0,7,0,7,0,7,0,7,0,7,0,7,0,7,0,7,0,7,0,7,0,0},
                                             {0,7,0,7,0,7,0,7,0,7,0,7,0,7,0,7,0,7,0,7,0,7,0,7,0},
                                             {7,0,7,0,7,0,7,0,7,0,7,0,7,0,7,0,7,0,7,0,7,0,7,0,7},
                                             {0,0,0,0,0,0,0,0,0,2,0,2,0,2,0,2,0,0,0,0,0,0,0,0,0},
                                             {0,0,0,0,0,0,0,0,0,0,2,0,2,0,2,0,0,0,0,0,0,0,0,0,0},
                                             {0,0,0,0,0,0,0,0,0,0,0,2,0,2,0,0,0,0,0,0,0,0,0,0,0},
                                             {0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0}};


int main() {
    int x_from, y_from, x_to, y_to;
    int MOVE = RE;
    int x_to_multi_jump, y_to_multi_jump, y_from_multi_jump, x_from_multi_jump;
    int end_jump = 0;

    print_board();

    while (1) {


        if (MOVE == RE) {
            end_jump = 0;
            printf("RED's move:  ");
            scanf("%d %d %d %d", &x_from, &y_from, &x_to, &y_to);

            if (x_from == -1 && y_from == -1 && x_to == -1 && y_to == -1) {
                //printf("\n"); //added this when running test vectors
                return 0;
            }

            if (check_move(RE, x_from, y_from, x_to, y_to) == VALID_MOVE) {



                // Start MULTI JUMP MOVE
                if (check_jump(x_from, y_from, x_to, y_to) == VALID_MOVE) {


                    the_board[y_from][x_from] = EM;
                    the_board[y_to][x_to] = RE;

                while (is_jumper(x_from, y_from, x_to, y_to) == TRUE) {
                    end_jump = 1;
                    printf("\n"); //added this when running test vectors
                    print_board();

                    printf("RED's move:  ");
                    scanf("%d %d %d %d", &x_from_multi_jump, &y_from_multi_jump, &x_to_multi_jump, &y_to_multi_jump);

                    if (x_from_multi_jump == -1 && y_from_multi_jump == -1 && x_to_multi_jump == -1 &&
                        y_to_multi_jump == -1) {
                        end_jump = 0;
                        break;
                    }

                    if ((x_from_multi_jump == x_to && y_from_multi_jump == y_to) && (x_to_multi_jump != x_from || y_to_multi_jump != y_from) &&
                        check_jump(x_from_multi_jump, y_from_multi_jump, x_to_multi_jump, y_to_multi_jump) ==
                        VALID_MOVE) {

                        the_board[y_from_multi_jump][x_from_multi_jump] = EM;
                        the_board[y_to_multi_jump][x_to_multi_jump] = RE;
                        //printf("\n"); //added this when running test vectors
                        //print_board(); //added this when running test vectors

                        x_from = x_from_multi_jump;
                        y_from = y_from_multi_jump;
                        x_to = x_to_multi_jump;
                        y_to = y_to_multi_jump;

                    } else {
                        printf("INVALID MOVE.  TRY AGAIN!!\n");
                        continue;
                    }
                }
            }
                // End MULTI JUMP MOVE


                //THE GOAL OF THIS LINE IS TO BREAK OUT OF THE PLAYERS LOOP BEFORE IT PRINTS ANOTHER BOARD IF AND
                //ONLY IF THE PLAYER JUST JUMPED AND DOESN'T MAKE ANOTHER JUMP
                if (end_jump == 0){
                    the_board[y_from][x_from] = EM;
                    the_board[y_to][x_to] = RE;
                    printf("\n");
                    print_board();
                }
            }



            else if (check_move(RE, x_from, y_from, x_to, y_to) == INVALID_MOVE) {
                printf("INVALID MOVE.  TRY AGAIN!!\n");
                continue;
            }
            MOVE = GR;
        }


        if (MOVE == GR) {
            end_jump = 0;
            printf("GREEN's move:  ");
            scanf("%d %d %d %d", &x_from, &y_from, &x_to, &y_to);

            if (x_from == -1 && y_from == -1 && x_to == -1 && y_to == -1) {
                //printf("\n"); //added this when running test vectors
                return 0;
            }

            if (check_move(GR, x_from, y_from, x_to, y_to) == VALID_MOVE) {



                // Start MULTI JUMP MOVE
                if (check_jump(x_from, y_from, x_to, y_to) == VALID_MOVE) {

                    the_board[y_from][x_from] = EM;
                    the_board[y_to][x_to] = GR;

                    while (is_jumper(x_from, y_from, x_to, y_to) == TRUE) {
                        end_jump = 1;
                        printf("\n"); //added this when running test vectors
                        print_board();

                        printf("GREEN's move:  ");
                        scanf("%d %d %d %d", &x_from_multi_jump, &y_from_multi_jump, &x_to_multi_jump, &y_to_multi_jump);

                        if (x_from_multi_jump == -1 && y_from_multi_jump == -1 && x_to_multi_jump == -1 &&
                            y_to_multi_jump == -1) {
                            end_jump = 0;
                            break;
                        }

                        if ((x_from_multi_jump == x_to && y_from_multi_jump == y_to) && (x_to_multi_jump != x_from || y_to_multi_jump != y_from) &&
                            check_jump(x_from_multi_jump, y_from_multi_jump, x_to_multi_jump, y_to_multi_jump) ==
                            VALID_MOVE) {

                            the_board[y_from_multi_jump][x_from_multi_jump] = EM;
                            the_board[y_to_multi_jump][x_to_multi_jump] = GR;
                            //printf("\n"); //added this when running test vectors
                            //print_board();

                            x_from = x_from_multi_jump; //these four lines ARE necessary
                            y_from = y_from_multi_jump;
                            x_to = x_to_multi_jump;
                            y_to = y_to_multi_jump;

                        } else {
                            printf("INVALID MOVE.  TRY AGAIN!!\n");
                            continue;
                        }
                    }
                }

                // End MULTI JUMP MOVE


                //THE GOAL OF THIS LINE IS TO BREAK OUT OF THE PLAYERS LOOP BEFORE IT PRINTS ANOTHER BOARD IF AND
                //ONLY IF THE PLAYER JUST JUMPED AND DOESN'T MAKE ANOTHER JUMP
                if (end_jump == 0){
                    the_board[y_from][x_from] = EM;
                    the_board[y_to][x_to] = GR;
                    printf("\n"); //added this when running test vectors
                    print_board();
                }
            }


            else if (check_move(GR, x_from, y_from, x_to, y_to) == INVALID_MOVE) {
                printf("INVALID MOVE.  TRY AGAIN!!\n");
                continue;
            }



            MOVE = RE;
        }
    }
}


void print_board() {
    int k, i, j;
    printf("  "); //changed this "   " to "  " when running test vectors
    for (k=0;k<BOARD_SIZE_X;k++) {
        if (k == BOARD_SIZE_X - 1)
            printf("%3d ", k);
        else
            printf("%3d", k);
    }
    printf("\n");
    for (i=0;i<BOARD_SIZE_Y;i++){
        printf("%2d ", i); //changed this %3d to %2d when running test vectors
        for (j=0;j<BOARD_SIZE_X;j++) {
            if (the_board[i][j] == 0) {
                printf("   ");
            } else if (the_board[i][j] == RE) { //red
                printf(" R ");
            } else if (the_board[i][j] == GR) { //green
                printf(" G ");
            } else if (the_board[i][j] == EM) { //blank
                printf(" - ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int check_neighbor(int x_from, int y_from, int x_to, int y_to) {
    //since there are 6 possible neighboring positions, have 6 if() conditional checks
    if ((x_to == x_from + 2) && (y_to == y_from)){
        return VALID_MOVE;
    }
    else if ((x_to == x_from + 1) && (y_to == y_from + 1)){
        return VALID_MOVE;
    }
    else if((x_to == x_from - 1) && (y_to == y_from + 1)){
        return VALID_MOVE;
    }
    else if((x_to == x_from - 2) && (y_to == y_from)){
        return VALID_MOVE;
    }
    else if((x_to == x_from - 1) && (y_to == y_from - 1)){
        return VALID_MOVE;
    }
    else if((x_to == x_from + 1) && (y_to == y_from - 1)){
        return VALID_MOVE;
    }
    else{
        return INVALID_MOVE;
    }
}


int check_jump(int x_from, int y_from, int x_to, int y_to) {
    //since there are 6 possible jump moves, have 6 if() conditional checks
    if ( (x_to == x_from + 2) && (y_to == y_from + 2)  &&  (the_board[y_from+1][x_from+1] != EM)  &&  (the_board[y_from+2][x_from+2] == EM)  ) {
            return VALID_MOVE;
    }
    else if ( (x_to == x_from + 4) && (y_to == y_from)  &&  (the_board[y_from][x_from+2] != EM)  &&  (the_board[y_from][x_from+4] == EM)  ) {
            return VALID_MOVE;
    }
    else if ( (x_to == x_from + 2) && (y_to == y_from - 2)  &&  (the_board[y_from-1][x_from+1] != EM)  &&  (the_board[y_from-2][x_from+2] == EM)  ) {
        return VALID_MOVE;
    }
    else if ( (x_to == x_from - 2) && (y_to == y_from - 2)  &&  (the_board[y_from-1][x_from-1] != EM)  &&  (the_board[y_from-2][x_from-2] == EM)  ) {
        return VALID_MOVE;
    }
    else if ( (x_to == x_from - 4) && (y_to == y_from)  &&  (the_board[y_from][x_from-2] != EM)  &&  (the_board[y_from][x_from-4] == EM)  ) {
        return VALID_MOVE;
    }
    else if ( (x_to == x_from - 2) && (y_to == y_from + 2)  &&  (the_board[y_from+1][x_from-1] != EM)  &&  (the_board[y_from+2][x_from-2] == EM)  ) {
        return VALID_MOVE;
    }
    else {
        return INVALID_MOVE;
    }
}


int check_move(int color, int x_from, int y_from, int x_to, int y_to){

    //check to see if: the move originates from and terminates to spaces on the board
    if ( the_board[y_from][x_from] != DA && the_board[y_to][x_to] != DA && the_board[y_to][x_to] == EM &&
    the_board[y_from][x_from] == color && (check_neighbor(x_from, y_from, x_to, y_to) == VALID_MOVE ||
    check_jump(x_from, y_from, x_to, y_to) == VALID_MOVE) ){
        return VALID_MOVE;
    }

    else
        return INVALID_MOVE;
}


int is_jumper(int x_from, int y_from, int x_to, int y_to){
    //check to see if the marble, now at x_to and y_to, can make a valid jumping move over any one of its neighbors
    if ((check_jump(x_to, y_to, x_to+2, y_to+2) == VALID_MOVE) && (x_to+2 != x_from || y_to+2 != y_from)){
        return TRUE;
    }
    if ((check_jump(x_to, y_to, x_to+4, y_to) == VALID_MOVE) && (x_to+4 != x_from || y_to != y_from)){
        return TRUE;
    }
    if ((check_jump(x_to, y_to, x_to+2, y_to-2) == VALID_MOVE) && (x_to+2 != x_from || y_to-2 != y_from)){
        return TRUE;
    }
    if ((check_jump(x_to, y_to, x_to-2, y_to-2) == VALID_MOVE) && (x_to-2 != x_from || y_to-2 != y_from)){
        return TRUE;
    }
    if ((check_jump(x_to, y_to, x_to-4, y_to) == VALID_MOVE) && (x_to-4 != x_from || y_to != y_from)){
        return TRUE;
    }
    if ((check_jump(x_to, y_to, x_to-2, y_to+2) == VALID_MOVE) && (x_to-2 != x_from || y_to+2 != y_from)){
        return TRUE;
    }

    return FALSE;
}





