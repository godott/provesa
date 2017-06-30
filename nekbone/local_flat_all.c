
void local_flat_all(double **w, double **u, double *** gxyz, int n, double **D){
    
    double temp, tempr, temps, tempt, wr, ws, wt;

    double ur[n+1][n+1], us[n+1][n+1], ut[n+1][n+1];

    int i, j, k, l;
    
    for(l = 0; l <= n; l++){
        for(j = 0; j <= n; j++){
            for(i = 0; i <= n; i++){
                tempr = 0.0;
                temps = 0.0;
                tempt = 0.0;

                for(k = 0; k <= n; k++){
                    tempr = tempr + D[k][i] * (*u)[l*NUMGP*NUMGP+j*NUMGP+k];
                    temps = temps + D[k][j] * (*u)[l*NUMGP*NUMGP+k*NUMGP+i];
                    tempt = tempt + D[k][l] * (*u)[k*NUMGP*NUMGP+j*NUMGP+i];
                }

                wr = (*gxyz)[i][0] * tempr + (*gxyz)[i][1] * temps + (*gxyz)[i][2] * tempt;
                ws = (*gxyz)[i][1] * tempr + (*gxyz)[i][3] * temps + (*gxyz)[i][4] * tempt;
                wt = (*gxyz)[i][2] * tempr + (*gxyz)[i][4] * temps + (*gxyz)[i][5] * tempt;
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
            (*w)[NUMGP*NUMGP*l + NUMGP*i + j] = temp;
        }
    }
}
