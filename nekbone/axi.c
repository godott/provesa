#include "timeit.h"
/*Matrix-vector product: w=A*u*/

void local_grad3(double ur[n], double us[n], double ut[n], double **u, int ni, double D[nx1][nx1], double Dt[nx1][nx1]);
void local_grad3_t(double **u, double ur[n], double us[n], double ut[n], int ni, double D[nx1][nx1], double Dt[nx1][nx1]);
void axi(double **w, double **u, double ***gxyz, int ni, int fel, int lel, int find, int lind){

    int e, i, j, e16, wr, ws, wt;

    double dxm1[nx1][nx1];
    double dxtm1[nx1][nx1];

    for(i = 0; i < nx1; i++){
        for(j =0; j < nx1; j++){
            dxm1[i][j] = 1.0 + 1.0/(1.0*(i + 2*j + 3));
            dxtm1[j][i] = 1.0 + 1.0/(1.0*(i+ 2*j + 3));
        }
    }

    double ur[n], us[n], ut[n];

    for(e = fel; e <= lel; e++){
         if(e < nelt) {
             local_grad3(ur, us, ut, u+e, nx1-1, dxm1, dxtm1);

         for(i = 1; i <= n; i++){
                wr = (*(gxyz+e))[i][0] * ur[i] + (*gxyz)[i][1] * us[i] + (*gxyz)[i][2] * ut[i];
                ws = (*(gxyz+e))[i][1] * ur[i] + (*gxyz)[i][3] * us[i] + (*gxyz)[i][4] * ut[i];
                wt = (*(gxyz+e))[i][2] * ur[i] + (*gxyz)[i][4] * us[i] + (*gxyz)[i][5] * ut[i];
         }

         ur[i] = wr;
         us[i] = ws;
         ut[i] = wt;
         
         }

         local_grad3_t(w + e, ur, us, ut, nx1 - 1, dxm1, dxtm1);
    }
    return;
}


