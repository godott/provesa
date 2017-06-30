#include "timeit.h"
void local_flat_all(double **w, double **u, double *** gxyz, int n, double D[nx1][nx1]){

    double temp, tempr, temps, tempt, wr, ws, wt;


    double ur[16][n+1][n+1][n+1], us[16][n+1][n+1][n+1], ut[16][n+1][n+1][n+1];
    int i, j, k, l, e;

    for(e = 0; e < 16; e++){

    for(l = 0; l <= n; l++){
        for(j = 0; j <= n; j++){
            for(i = 0; i <= n; i++){
                tempr = 0.0;
                temps = 0.0;
                tempt = 0.0;

                for(k = 0; k <= n; k++){
                    tempr = tempr + D[k][i] * (*(u+e))[l*nx1*nx1+j*nx1+k];
                    temps = temps + D[k][j] * (*(u+e))[l*nx1*nx1+k*nx1+i];
                    tempt = tempt + D[k][l] * (*(u+e))[k*nx1*nx1+j*nx1+i];
                }

                wr = (*(gxyz+e))[i][0] * tempr + (*(gxyz+e))[i][1] * temps + (*(gxyz+e))[i][2] * tempt;
                ws = (*(gxyz+e))[i][1] * tempr + (*(gxyz+e))[i][3] * temps + (*(gxyz+e))[i][4] * tempt;
                wt = (*(gxyz+e))[i][2] * tempr + (*(gxyz+e))[i][4] * temps + (*(gxyz+e))[i][5] * tempt;
                
                ur[e][l][j][i] = wr;
                us[e][l][j][i] = ws;
                ut[e][l][j][i] = wt;

            }
        }
    }

    for(l = 0; l <= n; l++){
        for(j = 0; j <= n; j++){
            for(i = 0; i <= n; i++){
                    temp = 0.0;
                    for(k = 0; k <= n; k++){

                        temp = temp + D[i][k] * ur[e][l][j][i];
                        temp = temp + D[j][k] * us[e][l][k][i];
                        temp = temp + D[l][k] * ut[e][k][j][i];
                    }

                (*(w+e))[nx1*nx1*l + nx1*i + j] = temp;
            }

        }
    }
    }
}
