#include "timeit.h"

void mxm(double a[][], int n1, double b[][], int n2, double c[][], int n3);
void local_grad3(double ur[nx1][nx1][nx1], double us[nx1][nx1][nx1], double ut[nx1][nx1][nx1], double **u, int ni, double D[nx1][nx1], double Dt[nx1][nx1]){
       int m1 = ni + 1;
       int m2 = m1 * m1;
       int i, j, k;
    
       double u_1[m1][m2], u_2[m1][m1][m1], u_3[m2][m1], ut_temp ;

       for(i = 0; i < m1; i++){
           for(j = 0; j < m1; i++){
               for(k = 0; k < m1; i++){
                    u_1[i][j*m1+k] = u[i*m1*m1+j*m1+k];
                    u_2[j][i][k] = u[i*m1*m1+j*m1+k];
                    u_3[i*m1+j][k] = u[i*m1*m1+j*m1+k];
               }
           }

       }

       mxm(D, m1, u_1, m1, ur, m2);

       for(k = 0; k <= ni; k++){
            mxm(u_2[k], m1,Dt, m1, us[k], m1);
       }

        mxm(u_3, m2,Dt, m1,ut, m1);

        return;
    
}
