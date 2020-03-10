#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

#define MAX 4
/* 
3 3
0 0 0
0 1 1
0 0 0
0 2
2 2
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
    bool isBispo = true;
    printf("(%d,%d)\n", x, y);
    for(int i = x-1, j = y-1; isValidXY(i, j, I, J); i--, j--){
        if(M[i][j] == 'v') {
            isBispo = false;
        } else if(M[i][j] == 'o') {
            break;
        }
    }
    printf("%d, %d - %d", x, y, isBispo);
    for(int i = x-1, j = y+1; isValidXY(i, j, I, J); i--, j++){
        if(M[i][j] == 'v') {
            isBispo = false;
        } else if(M[i][j] == 'o') {
            break;
        }
    }
    for(int i = x+1, j = y-1; isValidXY(i, j, I, J); i++, j--){
        if(M[i][j] == 'v') {
            isBispo = false;
        } else if(M[i][j] == 'o') {
            break;
        }
    }
    for(int i = x+1, j = y+1; isValidXY(i, y, j, J); i++, j++){
        if(M[i][j] == 'v') {
            isBispo = false;
        } else if(M[i][j] == 'o') {
            break;
        }
    }
    return isBispo;
}

bool isTower(int x, int y, int I, int J){
    bool isTorre = true;
    for(int i = x, j = y-1; isValidXY(i, j, I, J); j--){
        if(M[i][j] == 'v') {
            isTorre = false;
        } else if(M[i][j] == 'o') {
            break;
        }
    }
    for(int i = x, j = y+1; isValidXY(i, j, I, J); j++){
        if(M[i][j] == 'v') {
            isTorre = false;
        } else if(M[i][j] == 'o') {
            break;
        }
    }
    for(int i = x+1, j = y; isValidXY(i, j, I, J); i++){
        if(M[i][j] == 'v') {
            isTorre = false;
        } else if(M[i][j] == 'o') {
            break;
        }
    }
    for(int i = x-1, j = y; isValidXY(i, j, I, J); i--){
        if(M[i][j] == 'v') {
            isTorre = false;
        } else if(M[i][j] == 'o') {
            break;
        }
    }
    return isTorre;
}

// bool isBispo(int x, int y, int I, int J) {
//     return ((!isValidXY(x-1, y-1, I, J) || (isValidXY(x-1, y-1, I, J) && M[x-1][y-1]!='v'))
//     && (!isValidXY(x+1, y-1, I, J) || (isValidXY(x+1, y-1, I, J) && M[x+1][y-1]!='v'))
//     && (!isValidXY(x-1, y+1, I, J) || (isValidXY(x-1, y+1, I, J) && M[x-1][y+1]!='v'))
//     && (!isValidXY(x+1, y+1, I, J) || (isValidXY(x+1, y+1, I, J) && M[x+1][y+1]!='v')));
// }

// bool isTorre(int x, int y, int I, int J) {
//     return ((!isValidXY(x-1, y, I, J) || (isValidXY(x-1, y, I, J) && M[x-1][y]!='v'))
//     && (!isValidXY(x+1, y, I, J) || (isValidXY(x+1, y, I, J) && M[x+1][y]!='v'))
//     && (!isValidXY(x, y+1, I, J) || (isValidXY(x, y+1, I, J) && M[x][y+1]!='v'))
//     && (!isValidXY(x+1, y, I, J) || (isValidXY(x+1, y, I, J) && M[x+1][y]!='v')));
// }

bool isRainha(int x, int y, int I, int J){
    return isBishop(x, y, I, J) && isTower(x, y, I, J);
    // && (!isValidXY(x-2, y-2, I, J) || (isValidXY(x-2, y-2, I, J) && M[x-2][y-2]!='v') || (isValidXY(x-2, y-2, I, J) && M[x-2][y-2]=='o'))
    // && (!isValidXY(x-2, y, I, J) || (isValidXY(x-2, y, I, J) && M[x-2][y]!='v') || (isValidXY(x-2, y, I, J) && M[x-2][y]=='o'))
    // && (!isValidXY(x-2, y+2, I, J) || (isValidXY(x-2, y+2, I, J) && M[x-2][y+2]!='v') || (isValidXY(x-2, y+2, I, J) && M[x-2][y+2]=='o'))
    // && (!isValidXY(x, y-2, I, J) || (isValidXY(x, y-2, I, J) && M[x][y-2]!='v') || (isValidXY(x, y-2, I, J) && M[x][y-2]=='o'))
    // && (!isValidXY(x, y+2, I, J) || (isValidXY(x, y+2, I, J) && M[x][y+2]!='v') || (isValidXY(x, y+2, I, J) && M[x][y+2]=='o'))
    // && (!isValidXY(x+2, y-2, I, J) || (isValidXY(x+2, y-2, I, J) && M[x+2][y-2]!='v') || (isValidXY(x+2, y-2, I, J) && M[x+2][y-2]=='o'))
    // && (!isValidXY(x+2, y, I, J) || (isValidXY(x+2, y, I, J) && M[x+2][y]!='v') || (isValidXY(x+2, y, I, J) && M[x+2][y]=='o'))
    // && (!isValidXY(x+2, y+2, I, J) || (isValidXY(x+2, y+2, I, J) && M[x+2][y+2]!='v') || (isValidXY(x+2, y+2, I, J) && M[x+2][y+2]=='o'));
}

bool isRei(int x, int y, int I, int J) {
    return ((!isValidXY(x-1, y-1, I, J) || (isValidXY(x-1, y-1, I, J) && M[x-1][y-1]!='v'))
    && (!isValidXY(x+1, y+1, I, J) || (isValidXY(x+1, y+1, I, J) && M[x+1][y+1]!='v'))
    && (!isValidXY(x-1, y+1, I, J) || (isValidXY(x-1, y+1, I, J) && M[x-1][y+1]!='v'))
    && (!isValidXY(x+1, y-1, I, J) || (isValidXY(x+1, y-1, I, J) && M[x+1][y-1]!='v'))
    && (!isValidXY(x-1, y, I, J) || (isValidXY(x-1, y, I, J) && M[x-1][y]!='v'))
    && (!isValidXY(x+1, y, I, J) || (isValidXY(x+1, y, I, J) && M[x+1][y]!='v'))
    && (!isValidXY(x, y+1, I, J) || (isValidXY(x, y+1, I, J) && M[x][y+1]!='v'))
    && (!isValidXY(x, y-1, I, J) || (isValidXY(x, y-1, I, J) && M[x][y-1]!='v')));
}

bool isCavalo(int x, int y, int I, int J) {
    return ((!isValidXY(x-1, y-2, I, J) || (isValidXY(x-1, y-2, I, J) && M[x-1][y-2]!='v'))
    && (!isValidXY(x-1, y+2, I, J) || (isValidXY(x-1, y+2, I, J) && M[x-1][y+2]!='v'))
    && (!isValidXY(x-2, y+1, I, J) || (isValidXY(x-2, y+1, I, J) && M[x-2][y+1]!='v'))
    && (!isValidXY(x-2, y-1, I, J) || (isValidXY(x-2, y-1, I, J) && M[x-2][y-1]!='v'))
    && (!isValidXY(x+1, y+2, I, J) || (isValidXY(x+1, y+2, I, J) && M[x+1][y+2]!='v'))
    && (!isValidXY(x+1, y-2, I, J) || (isValidXY(x+1, y-2, I, J) && M[x+1][y-2]!='v'))
    && (!isValidXY(x+2, y+1, I, J) || (isValidXY(x+2, y+1, I, J) && M[x+2][y+1]!='v'))
    && (!isValidXY(x+2, y-1, I, J) || (isValidXY(x+2, y-1, I, J) && M[x+2][y-1]!='v')));
}

bool isPeao(int x, int y, int I, int J) {
    return ((!isValidXY(x-1, y-1, I, J) || (isValidXY(x-1, y-1, I, J) && M[x-1][y-1]!='v'))
    && (!isValidXY(x+1, y+1, I, J) || (isValidXY(x+1, y+1, I, J) && M[x+1][y+1]!='v')));
}


void monta(int I, int J, int x, int y) {
    if(((x-1)*(y+1))==I*J) return;
    if(M[x][y]=='o'){
        printf("1");
        if(isRainha(x, y, I, J)) {
            printf("(%d, %d) - Pode ter uma rainha\n", x, y);
        }
        else if(isRei(x, y, I, J)) {
            printf("(%d, %d) - Pode ter um rei\n", x, y);
        }
        else if(isBishop(x, y, I, J)) {
            printf("(%d, %d) - Pode ter um bispo\n", x, y);
        }
        else if(isTower(x, y, I, J)) {
            printf("(%d, %d) - Pode ter uma torre\n", x, y);
        }
        else if(isCavalo(x, y, I, J)) {
            printf("(%d, %d) - Pode ter um cavalo\n", x, y);
        }
        else if(isPeao(x, y, I, J)) {
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
    monta(I, J, 0, 0);
    return 0;
}