#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

/* 
3 3
0 0 0
0 1 1
0 0 0
0 2
2 2
*/


bool temCaminho(int **M, int I, int J, 
             int x, int y,
             int x2, int y2) {
    M[x][y] = 2;

    if(x >= 0 && x < I && y >= 0 && y < J){
        if(M[x + 1][y] == 0) {
            if (!temCaminho(M, I, J, x + 1, y, x2, y2)) {
                M[x][y] = 0;
            }
        }
        else if(M[x + 1][y] == 0) {
            if (!temCaminho(M, I, J, x + 1, y, x2, y2)) {
                M[x][y] = 0;
            }
        }
        else if(M[x + 1][y] == 0) {
            if (!temCaminho(M, I, J, x + 1, y, x2, y2)) {
                M[x][y] = 0;
            }
        }
        else if(M[x + 1][y] == 0) {
            if (!temCaminho(M, I, J, x + 1, y, x2, y2)) {
                M[x][y] = 0;
            }
        }
        else if(M[x + 1][y] == 0) {
            if (!temCaminho(M, I, J, x + 1, y, x2, y2)) {
                M[x][y] = 0;
            }
        }else return false;
    }
    
    if(x == x2 && y == y2) {
        return true;
    }
} 

int main() {
    int I, J, x1, y1, x2, y2;
    int M[I][J];
    scanf("%d %d", &I, &J);

    for(int i = 0; i < I; i++){
        for(int j = 0; j < J; j++){
            scanf("%d", &M[i][j]);
        }
    }

    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    printf("%d", temCaminho(M, I, J, x1, y1, x2, y2));
    return 0;
}