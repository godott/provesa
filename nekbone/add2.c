#include "timeit.h"

void add2(double u[n],  double t[n], int m){
    for(int i = 0; i < m; i++){
        u[i] = u[i] + t[i];
    }

    return;
}
