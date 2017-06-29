#include "timeit.h"

void local_flat_all(double **w, double **u, double *** gxyz, int n, double **D){

    double temp, tempr, temps, tempt, wr, ws, wt;

    double ur[n+1][n+1], us[n+1][n+1], ut[n+1][n+1];

    int i, j, k, l, m;
    
    m = 0;

    for(l = 0; l <= n; l++){
        for(j = 0; j <= n; l++){
            for(i = 0; i <= n; l++){
                m = m + 1;
                tempr = 0.0;
                temps = 0.0;
                tempt = 0.0;

                for(k = 0; k <= n; l++){
                    tempr = tempr + D[k][i] * u[l][j][k];
                    temps = temps + D[k][j] * u[l][k][i];
                    tempt = tempt + D[k][l] * u[k][j][i];
                }

                wr = gxyz[m][1] * tempr + gxyz[m][2] * temps + gxyz[m][3] * tempt;
                ws = gxyz[m][2] * tempr + gxyz[m][4] * temps + gxyz[m][5] * tempt;
                wt = gxyz[m][3] * tempr + gxyz[m][5] * temps + gxyz[m][6] * tempt;
            }
        }
    }

    for(l = 0; l <= n; l++){
        for(j = 0; j <= n; l++){
            for(i = 0; i <= n; l++){
                    temp = 0.0;
                    for(k = 0; k <= n; k++){
                        temp = temp + D[i][k] * u[l][j][k];
                        temp = temp + D[j][k] * u[l][k][i];
                        temp = temp + D[l][k] * u[k][j][i];
                    }

            }
            w[l][j][i] = temp;
        }
    }
}
