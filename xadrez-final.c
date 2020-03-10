// Author: Victor Yan Pereira e Lima

#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

#define MAX 10
/* 
5 5
a v a v a
v a a a v
a a o a a
v a a a v
a v a v a

8 8
v a v a v v v v
a v v v a v v v
v v o v v v v v
a v v v a v a v
v a v a v v v o
v v v v v v v v
v v v v v a a a
v v v v v a o a

8 8
v a v a v v v v
a v v v a v v v
v v o v v v v v
a v v v a v v v
v a v a v v v v
v v v v v v v v
v v v v v a a a
v v v v v a o a
*/

char M[MAX][MAX];

void printM(int I, int J) {
    for (int i = 0; i < I; i++) {
        for (int j = 0; j < J; j++) { 
            printf("%c ", M[i][j]);
        }
        printf("\n");
    }
}

bool isValidXY(int x, int y, int I, int J) {
    return (x >= 0 && x < I && y >= 0 && y < J);
}

bool isBishop(int x, int y, int I, int J){
    bool valido = true;
    for(int i = x-1, j = y-1; isValidXY(i, j, I, J); i--, j--){
        if(M[i][j] == 'v') {
            valido = false;
        } else if(M[i][j] == 'o') {
            break;
        }
    }
    for(int i = x-1, j = y+1; isValidXY(i, j, I, J); i--, j++){
        if(M[i][j] == 'v') {
            valido = false;
        } else if(M[i][j] == 'o') {
            break;
        }
    }
    for(int i = x+1, j = y-1; isValidXY(i, j, I, J); i++, j--){
        if(M[i][j] == 'v') {
            valido = false;
        } else if(M[i][j] == 'o') {
            break;
        }
    }
    for(int i = x+1, j = y+1; isValidXY(i, j, I, J); i++, j++){
        if(M[i][j] == 'v') {
            valido = false;
        } else if(M[i][j] == 'o') {
            break;
        }
    }
    return valido;
}

bool isTower(int x, int y, int I, int J){
    bool valido = true;
    for(int i = x, j = y-1; isValidXY(i, j, I, J); j--){
        if(M[i][j] == 'v') {
            valido = false;
        } else if(M[i][j] == 'o') {
            break;
        }
    }
    for(int i = x, j = y+1; isValidXY(i, j, I, J); j++){
        if(M[i][j] == 'v') {
            valido = false;
        } else if(M[i][j] == 'o') {
            break;
        }
    }
    for(int i = x+1, j = y; isValidXY(i, j, I, J); i++){
        if(M[i][j] == 'v') {
            valido = false;
        } else if(M[i][j] == 'o') {
            break;
        }
    }
    for(int i = x-1, j = y; isValidXY(i, j, I, J); i--){
        if(M[i][j] == 'v') {
            valido = false;
        } else if(M[i][j] == 'o') {
            break;
        }
    }
    return valido;
}

bool isQueen(int x, int y, int I, int J){
    return isBishop(x, y, I, J) && isTower(x, y, I, J);
}

bool isKing(int x, int y, int I, int J) {
    return ((!isValidXY(x-1, y-1, I, J) || (isValidXY(x-1, y-1, I, J) && M[x-1][y-1]!='v'))
    && (!isValidXY(x+1, y+1, I, J) || (isValidXY(x+1, y+1, I, J) && M[x+1][y+1]!='v'))
    && (!isValidXY(x-1, y+1, I, J) || (isValidXY(x-1, y+1, I, J) && M[x-1][y+1]!='v'))
    && (!isValidXY(x+1, y-1, I, J) || (isValidXY(x+1, y-1, I, J) && M[x+1][y-1]!='v'))
    && (!isValidXY(x-1, y, I, J) || (isValidXY(x-1, y, I, J) && M[x-1][y]!='v'))
    && (!isValidXY(x+1, y, I, J) || (isValidXY(x+1, y, I, J) && M[x+1][y]!='v'))
    && (!isValidXY(x, y+1, I, J) || (isValidXY(x, y+1, I, J) && M[x][y+1]!='v'))
    && (!isValidXY(x, y-1, I, J) || (isValidXY(x, y-1, I, J) && M[x][y-1]!='v')));
}

bool isHorse(int x, int y, int I, int J) {
    return ((!isValidXY(x-1, y-2, I, J) || (isValidXY(x-1, y-2, I, J) && M[x-1][y-2]!='v'))
    && (!isValidXY(x-1, y+2, I, J) || (isValidXY(x-1, y+2, I, J) && M[x-1][y+2]!='v'))
    && (!isValidXY(x-2, y+1, I, J) || (isValidXY(x-2, y+1, I, J) && M[x-2][y+1]!='v'))
    && (!isValidXY(x-2, y-1, I, J) || (isValidXY(x-2, y-1, I, J) && M[x-2][y-1]!='v'))
    && (!isValidXY(x+1, y+2, I, J) || (isValidXY(x+1, y+2, I, J) && M[x+1][y+2]!='v'))
    && (!isValidXY(x+1, y-2, I, J) || (isValidXY(x+1, y-2, I, J) && M[x+1][y-2]!='v'))
    && (!isValidXY(x+2, y+1, I, J) || (isValidXY(x+2, y+1, I, J) && M[x+2][y+1]!='v'))
    && (!isValidXY(x+2, y-1, I, J) || (isValidXY(x+2, y-1, I, J) && M[x+2][y-1]!='v')));
}

bool isPawn(int x, int y, int I, int J) {
    return ((!isValidXY(x-1, y-1, I, J) || (isValidXY(x-1, y-1, I, J) && M[x-1][y-1]!='v'))
    && (!isValidXY(x+1, y+1, I, J) || (isValidXY(x+1, y+1, I, J) && M[x+1][y+1]!='v')));
}


void monta(int I, int J, int x, int y) {
    if((x-1)*J==I*J) return;
    if(M[x][y]=='o'){
        if(isQueen(x, y, I, J)) {
            printf("(%d, %d) - Pode ter uma rainha\n", x, y);
        }
        else if(isKing(x, y, I, J)) {
            printf("(%d, %d) - Pode ter um rei\n", x, y);
        }
        else if(isBishop(x, y, I, J)) {
            printf("(%d, %d) - Pode ter um bispo\n", x, y);
        }
        else if(isTower(x, y, I, J)) {
            printf("(%d, %d) - Pode ter uma torre\n", x, y);
        }
        else if(isHorse(x, y, I, J)) {
            printf("(%d, %d) - Pode ter um cavalo\n", x, y);
        }
        else if(isPawn(x, y, I, J)) {
            printf("(%d, %d) - Pode ter um peao\n", x, y);
        }
    }
    if(y == J - 1)
        monta(I, J, x+1, 0);
    else
        monta(I, J, x, y + 1);
}


int main() {
    int I, J;
    scanf("%d %d", &I, &J);

    for(int i = 0; i < I; i++){
        for(int j = 0; j < J; j++){
            scanf(" %c", &M[i][j]);
        }
    }
    printf("\n");
    printM(I, J);
    monta(I, J, 0, 0);
    return 0;
}