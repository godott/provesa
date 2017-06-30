#include "timeit.h"
/*Matrix-vector product: w=A*u*/

void local_flat_all(double **w, double **u, double *** gxyz, int n, double D[nx1][nx1]);
void axi(double **w, double **u, double ***gxyz, int n, int fel, int lel, int find, int lind){


    int e, i, j, e16;

    double dxm1[nx1][nx1];
    double dxtm1[nx1][nx1];

    for(i = 0; i < nx1; i++){
        for(j =0; j < nx1; j++){
            dxm1[i][j] = 1.0 + 1.0/(1.0*(i + 2*j + 3));
            dxtm1[j][i] = 1.0 + 1.0/(1.0*(i+ 2*j + 3));
        }
    }
    
    for(e16 = fel; e16 <= lel; e16 += 16){
            if(e16 < nelt)
                local_flat_all(w + e16, u + e16, gxyz + e16, nx1 - 1, dxm1);
    }
    return;
}


