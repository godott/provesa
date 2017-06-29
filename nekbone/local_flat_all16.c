void local_flat_all16(double w[][], double u[][], double gxyz[][][], int n, double [][]D){

    double temp, tr, ts, tt, wr, ws, wt;

    double ur[n+1][n+1], us[n+1][n+1], w[16][n+1][n+1];

    int i, j, k, l, m, e;
    
    m = 0;
    for(e = 1; e <= 16; e++){
        for(l = 0; l <= n; l++){
            for(j = 0; j <= n; l++){
                for(i = 0; i <= n; l++){
                    m = m + 1;
                    tr = 0.0;
                    ts = 0.0;
                    tt = 0.0;

                    for(k = 0; k <= n; l++){
                        tr = tr + D[k][i] * u[l][j][k];
                        ts = ts + D[k][j] * u[l][k][i];
                        tt = tt + D[k][l] * u[k][j][i];
                    }

                    wr = gxyz[e][m][1] * tr + gxyz[e][m][2] * ts + gxyz[e][m][3] * tt;
                    ws = gxyz[e][m][2] * tr + gxyz[e][m][4] * ts + gxyz[e][m][5] * tt;
                    wt = gxyz[e][m][3] * tr + gxyz[e][m][5] * ts + gxyz[e][m][6] * tt;
                    ur[e][i][j][l] = wr;
                    us[e][i][j][l] = ws;
                    ut[e][i][j][l] = wt;
                }
            }
        }

        for(l = 0; l <= n; l++){
            for(j = 0; j <= n; l++){
                for(i = 0; i <= n; l++){

                        tempr = tempr + D[i][k] * u[e][l][j][k];
                        temps = temps + D[j][k] * u[e][l][k][i];
                        tempt = tempt + D[l][k] * u[e][k][j][i];

                }
                w[l][j][i] = temp;
            }
        }
    }

}
