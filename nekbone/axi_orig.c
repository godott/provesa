#define NUMDIM 3

void axi(double w[][], double u[][], double gxyz[][][], int n, int fel, int lel, int find, int lind){
    int ldim = NUMDIM, nx1 = NUMGP, ny1 = NUMGP, nz1 = NUMGP, nelt = NUMEL, nxyz = nx1 * ny1 * nz1;

    extern double dxm1[nx1][nx1], dxtm1[nx1][nx1];
    double ur[16][nxyz], us[16][nxyz], ut[16][nxyz],ur2[16][nxyz], us2[16][nxyz], ut2[16][nxyz], ur3[16][nxyz], us3[16][nxyz], ut3[16][nxyz], w2[16][nxyz], w3[16][nxyz], w4[16][nxyz];

    double wr, ws, wt;
    int e, i, j, e16;

    for(e = fel; e <= lel; e++){

        local_grad3(ur[j][1], us[j][1], ut[j][1], u[e][1], nx1-1, dxm1, dxtm1);

        for(i = 1; i <= nxyz; i++){
            wr = gxyz(e, i, 1) * ur(j, i) + gxyz(e, i, 2) * us(j, i) +gxyz(e, i, 3) * ut(j, i);
            ws = gxyz(e, i, 2) * ur(j, i) + gxyz(e, i, 4) * us(j, i) +gxyz(e, i, 5) * ut(j, i);
            wt = gxyz(e, i, 3) * ur(j, i) + gxyz(e, i, 5) * us(j, i) +gxyz(e, i, 6) * ut(j, i);
            ur(j,i) = wr;
            us(j,i) = ws;
            ut(j,i) = wt;
        }

        local_grad3_t(w[e][1], ur[j][1], us[j][1], ut[j][1],nx1-1, dxm1, dxtm1);
    }
}
