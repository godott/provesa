#include "timeit.h"

void mxm(double a[][], int n1, double b[][], int n2, double c[][], int n3);
void add2(double u[nx1][nx1][nx1],  double t[nx1][nx1][nx1], int m);
void local_grad3_t(double **u, double ur[nx1][nx1][nx1], double us[nx1][nx1][nx1], double ut[nx1][nx1][nx1], int ni, double D[nx1][nx1], double Dt[nx1][nx1]){
    int m1 = ni + 1;
    int m2 = m1 * m1;
    int m3 = m1 * m1 * m1;
    int i, j, k;

   double u_1[m2][m1], u_2[m1][m1][m1], u_3[m1][m2], u_temp[m1][m1][m1], ur_temp[m2][m1], ut_temp[m1][m2];

   for(i = 0; i < m1; i++){
       for(j = 0; j < m1; j++){
           for(k = 0; k < m1; k++){
                ut_temp[i][j*m1+k] = ut[i][j][k];
                ur_temp[i*m1+j][k] = ur[i][j][k];
           }
       }
   }

   mxm(Dt, m1, ur_temp, m1, u_1, m2);

    for(k = 0; k <= ni; k++){
        mxm(us[k], m1, D, m1, u_2[k], m1);
    }
    
   for(i = 0; i < m1; i++){
       for(j = 0; j < m1; j++){
           for(k = 0; k < m1; k++){
               u_temp[i][j][k] = u_1[i*m1+j][k];
           }
       }
   }
    add2(u_2, u_temp, m1);

    mxm(ut_temp, m2, D, m1, u_3, m1);
   for(i = 0; i < m1; i++){
       for(j = 0; j < m1; j++){
           for(k = 0; k < m1; k++){
               u_temp[i][j][k] = u_3[i][m1*j+k];
           }
       }
   }
    add2(u_2, u_temp, m1);


   for(i = 0; i < m1; i++){
       for(j = 0; j < m1; j++){
           for(k = 0; k < m1; k++){
               (*u)[i*m1*m1+j*m1+k] = u_2[i][j][k];
           }
       }
   }
}

