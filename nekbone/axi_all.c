#include "timeit.h"
/*Matrix-vector product: w=A*u*/
void local_flat_all(double **w, double **u, double *** gxyz, int n, double **D);
void axi(double **w, double **u, double ***gxyz, int n, int fel, int lel, int find, int lind){

    int e, i, j, e16;

    for(e16 = fel; e16 <= lel; e16 += 16){
        for(j = 1; j <=16; j++){
            e = e16 + j -1;
            local_flat_all(w + e, u + e, gxyz + e, nx1 - 1, dxm1);
        }
    }
    return;
}

