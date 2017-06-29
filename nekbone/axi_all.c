#define NUMDIM 3


void axi(double w[][], double u[][], double gxyz[][][], int n, int fel, int lel, int find, int lind){
   
    extern int ldim, nx1, ny1, nz1, nelt, n;
    extern double dxm1[nx1][nx1], dxtm1[nx1][nx1];

    double ur[16][n], us[16][n], ut[16][n],ur2[16][n], us2[16][n], ut2[16][n], ur3[16][n], us3[16][n], ut3[16][n], w2[16][n], w3[16][n], w4[16][n];

    double wr, ws, wt;
    int e, i, j, e16;

    for(e16 = fel; e <= lel; e += 16){
        for(j = 1; j <=16; j++){
            e = e16 + j -1;
            local_flat_all(w3[j][1], u[e][1], gxyz[e][1][1], nx1-1, dxm1);
        }

    }

    return;

}

