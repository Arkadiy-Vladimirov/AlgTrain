#include <stdio.h>


/*there are 3 possible alternatives:            with extra conditions each:
    3 x in a row with no 3 o in a row               #{x} = #{o} + 1
    3 o in a row with no 3 x in a row               #{o} = #{x}
    nor x nor o make a row.                         #{x} = #{o} + 1 or #{x} = #{o}
*/

int main(int argc, char** argv) {
    
    //____input_&_counting____
    int game_board[3][3];
    int cardX = 0, cardO = 0;
    int i, j;

    for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {

        scanf("%d", &game_board[i][j]);

               if (game_board[i][j] == 1) {
            cardX++;
        } else if (game_board[i][j] == 2) {
            cardO++;
        }
    }
    }
    //_________________________
    

    //____3_in_a_row_check____
    int aux;
    int winX = 0; int winO = 0;

    //rows
    if (((aux = game_board[0][0]) == game_board[0][1]) && (game_board[0][1] == game_board[0][2])) {
        winX = winX || (aux == 1);
        winO = winO || (aux == 2);
    }

    if (((aux = game_board[1][0]) == game_board[1][1]) && (game_board[1][1] == game_board[1][2])) {
        winX = winX || (aux == 1);
        winO = winO || (aux == 2);
    }

    if (((aux = game_board[2][0]) == game_board[2][1]) && (game_board[2][1] == game_board[2][2])) {
        winX = winX || (aux == 1);
        winO = winO || (aux == 2);
    }

    //columns
    if (((aux = game_board[0][0]) == game_board[1][0]) && (game_board[1][0] == game_board[2][0])) {
        winX = winX || (aux == 1);
        winO = winO || (aux == 2);
    }

    if (((aux = game_board[0][1]) == game_board[1][1]) && (game_board[1][1] == game_board[2][1])) {
        winX = winX || (aux == 1);
        winO = winO || (aux == 2);
    }

    if (((aux = game_board[0][2]) == game_board[1][2]) && (game_board[1][2] == game_board[2][2])) {
        winX = winX || (aux == 1);
        winO = winO || (aux == 2);
    }

    //diagonals
    if (((aux = game_board[0][0]) == game_board[1][1]) && (game_board[1][1] == game_board[2][2])) {
        winX = winX || (aux == 1);
        winO = winO || (aux == 2);
    }

    if (((aux = game_board[0][2]) == game_board[1][1]) && (game_board[1][1] == game_board[2][0])) {
        winX = winX || (aux == 1);
        winO = winO || (aux == 2);
    }
    //____________________


    //____correctness_check____
    if ((winX == 0) && (winO == 0)) {
        if ((cardX == cardO + 1) || (cardX == cardO)) {
            printf("YES");
        } else {
            printf("NO");
        }

    } else if ((winX == 0) && (winO == 1)) {
        if (cardX == cardO) {
            printf("YES");
        } else {
            printf("NO");
        }

    } else if ((winX == 1) && (winO == 0)) {
        if (cardX == cardO + 1) {
            printf("YES");
        } else {
            printf("NO");
        }

    } else if ((winX == 1) && (winO == 1)) {
        printf("NO");
    }
    //_________________________

    return 0;
}