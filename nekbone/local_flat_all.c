#include "timeit.h"
void local_flat_all(double **w, double **u, double *** gxyz, int n, double D[nx1][nx1]){

    double temp, tempr, temps, tempt, wr, ws, wt;


    double ur[n+1][n+1][n+1], us[n+1][n+1][n+1], ut[n+1][n+1][n+1];
    int i, j, k, l;


    for(l = 0; l <= n; l++){
        for(j = 0; j <= n; j++){
            for(i = 0; i <= n; i++){
                tempr = 0.0;
                temps = 0.0;
                tempt = 0.0;

                for(k = 0; k <= n; k++){
                    tempr = tempr + D[k][i] * (*u)[l*nx1*nx1+j*nx1+k];
                    temps = temps + D[k][j] * (*u)[l*nx1*nx1+k*nx1+i];
                    tempt = tempt + D[k][l] * (*u)[k*nx1*nx1+j*nx1+i];
                }

                wr = (*gxyz)[i][0] * tempr + (*gxyz)[i][1] * temps + (*gxyz)[i][2] * tempt;
                ws = (*gxyz)[i][1] * tempr + (*gxyz)[i][3] * temps + (*gxyz)[i][4] * tempt;
                wt = (*gxyz)[i][2] * tempr + (*gxyz)[i][4] * temps + (*gxyz)[i][5] * tempt;
                
                ur[l][j][i] = wr;
                us[l][j][i] = ws;
                ut[l][j][i] = wt;

            }
        }
    }

    for(l = 0; l <= n; l++){
        for(j = 0; j <= n; j++){
            for(i = 0; i <= n; i++){
                    temp = 0.0;
                    for(k = 0; k <= n; k++){

                        temp = temp + D[i][k] * ur[l][j][i];
                        temp = temp + D[j][k] * us[l][k][i];
                        temp = temp + D[l][k] * ut[k][j][i];
                    }

                (*w)[nx1*nx1*l + nx1*i + j] = temp;
            }

        }
    }
}
