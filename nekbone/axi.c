#include "timeit.h"
/*Matrix-vector product: w=A*u*/

void local_grad3(double ur[nx1][nx1][nx1], double us[nx1][nx1][nx1], double ut[nx1][nx1][nx1], double **u, int ni, double D[nx1][nx1], double Dt[nx1][nx1]);
void local_grad3_t(double **u, double ur[nx1][nx1][nx1], double us[nx1][nx1][nx1], double ut[nx1][nx1][nx1], int ni, double D[nx1][nx1], double Dt[nx1][nx1]);
void axi(double **w, double **u, double ***gxyz, int ni, int fel, int lel, int find, int lind){

    int e, i, j, k, e16;
    double wr, ws, wt;

    double dxm1[nx1][nx1];
    double dxtm1[nx1][nx1];

    for(i = 0; i < nx1; i++){
        for(j =0; j < nx1; j++){
            dxm1[i][j] = 1.0 + 1.0/(1.0*(i + 2*j + 3));
            dxtm1[j][i] = 1.0 + 1.0/(1.0*(i+ 2*j + 3));
        }
    }

    double ur[nx1][nx1][nx1], us[nx1][nx1][nx1], ut[nx1][nx1][nx1];

    for(e = fel; e <= lel; e++){
         if(e < nelt) {
             local_grad3(ur, us, ut, u+e, nx1-1, dxm1, dxtm1);
             
        for(i = 0; i < nx1; i++){
            for(j =0; j < nx1; j++){
                for(k =0; k < nx1; k++){
                wr = (*(gxyz+e))[i*nx1*nx1+j*nx1+k][0] * ur[i][j][k] + (*(gxyz+e))[i*nx1*nx1+j*nx1+k][1] * us[i][j][k] + (*(gxyz+e))[i*nx1*nx1+j*nx1+k][2] * ut[i][j][k];
                ws = (*(gxyz+e))[i*nx1*nx1+j*nx1+k][1] * ur[i][j][k] + (*(gxyz+e))[i*nx1*nx1+j*nx1+k][3] * us[i][j][k] + (*(gxyz+e))[i*nx1*nx1+j*nx1+k][4] * ut[i][j][k];
                wt = (*(gxyz+e))[i*nx1*nx1+j*nx1+k][2] * ur[i][j][k] + (*(gxyz+e))[i*nx1*nx1+j*nx1+k][4] * us[i][j][k] + (*(gxyz+e))[i*nx1*nx1+j*nx1+k][5] * ut[i][j][k];
                ur[i][j][k]=wr;
                us[i][j][k]=ws;
                ut[i][j][k]=wt;

               }
            }
        }

       local_grad3_t(w + e, ur, us, ut, nx1 - 1, dxm1, dxtm1);
         }
    }
    return;
}
