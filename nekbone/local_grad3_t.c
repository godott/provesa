#include "timeit.h"

void mxm(double a[][], int n1, double b[][], int n2, double c[][], int n3);
void add2(double u[nx1][nx1][nx1],  double t[nx1][nx1][nx1], int m);
void local_grad3_t(double **u, double ur[nx1][nx1][nx1], double us[nx1][nx1][nx1], double ut[nx1][nx1][nx1], int ni, double D[nx1][nx1], double Dt[nx1][nx1]){
    int m1 = ni + 1;
    int m2 = m1 * m1;
    int m3 = m1 * m1 * m1;
    int k;

   double u_1[m1][m2], u_2[m1][m1][m1], u_3[m2][m1], u_temp[m1][m1][m1] ;

    mxm(Dt, m1, ur, m1, u, m2);

    for(k = 0; k <= ni; k++){
        mxm(us[k], m1, D, m1, u_temp[k], m1);
    }
    add2(*u, u_temp, m1);

    mxm(ut, m2, D, m1, u_temp, m1);
    add2(*u, u_temp, m1);

}

