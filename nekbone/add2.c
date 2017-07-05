#include "timeit.h"

void add2(double u[nx1][nx1][nx1],  double t[nx1][nx1][nx1], int m){
    int i, j, k;
    for(i = 0; i < m; i++){
        for(j = 0; j < m; i++){
            for(k = 0; k < m; i++){
                u[i][j][k] = u[i][j][k] + t[i][j][k];
            }
        }
    }

    return;
}
