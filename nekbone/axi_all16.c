#define NUMDIM 3

void axi(double w[][], double u[][], double gxyz[][][], int n, int fel, int lel, int find, int lind){
    int ldim = NUMDIM, nx1 = NUMGP, ny1 = NUMGP, nz1 = NUMGP, nelt = NUMEL, nxyz = nx1 * ny1 * nz1;

    extern double dxm1[nx1][nx1], dxtm1[nx1][nx1];
    double ur[16][nxyz], us[16][nxyz], ut[16][nxyz],ur2[16][nxyz], us2[16][nxyz], ut2[16][nxyz], ur3[16][nxyz], us3[16][nxyz], ut3[16][nxyz], w2[16][nxyz], w3[16][nxyz], w4[16][nxyz];

    double wr, ws, wt;
    int e, i, j, e16;

    for(e16 = fel; e <= lel; e += 16){
        local_flat_all16(w4, u[e16][1], gxyz[e16][1][1], nx1 - 1, dxm1);
    }
}
