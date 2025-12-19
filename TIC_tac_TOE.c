#include <stdio.h>

char board[3][3];

void initBoard() {
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            board[i][j]=' ';
}

void printBoard() {
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

int checkWin() {
    for(int i=0;i<3;i++)
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][0]!=' ')
            return 1;
    for(int i=0;i<3;i++)
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i] && board[0][i]!=' ')
            return 1;
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[0][0]!=' ')
        return 1;
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[0][2]!=' ')
        return 1;
    return 0;
}

int main() {
    int row, col, moves=0;
    char player='X';
    initBoard();
    while(1) {
        printBoard();
        printf("Player %c, enter row and column (0-2): ", player);
        scanf("%d %d",&row,&col);
        if(row<0 || row>2 || col<0 || col>2 || board[row][col]!=' ') {
            printf("Invalid move!\n");
            continue;
        }
        board[row][col]=player;
        moves++;
        if(checkWin()) {
            printBoard();
            printf("Player %c wins!\n", player);
            break;
        }
        if(moves==9) {
            printBoard();
            printf("It's a draw!\n");
            break;
        }
        player=(player=='X')?'O':'X';
    }
    return 0;
}
