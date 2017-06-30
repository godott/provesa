#include "timeit.h"

void mxm(void * a, int n1, void * b, int n2, void * c, int n3);
void add2(double u[n],  double t[n], int m);
void local_grad3_t(double **u, double ur[n], double us[n], double ut[n], int ni, double D[nx1][nx1], double Dt[nx1][nx1]){
    int m1 = ni + 1;
    int m2 = m1 * m1;
    int m3 = m1 * m1 * m1;
    int k;
    double temp[m3];

    mxm((void*)Dt, m1, (void *) ur, m1, (void *) (*u), m2);

    for(k = 0; k <= ni; k++){
        mxm((void *)(*(us + k * m1 * m1)), m1,(void *) D, m1, (void *)(temp + k * m1 * m1), m1);
    }
    add2(*u, temp, m3);

    mxm((void *) ut, m2, (void *) D, m1, (void *) temp, m1);
    add2(*u, temp, m3);

}

