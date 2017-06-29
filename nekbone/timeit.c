/****
 * This is a rewrite of timeit.f
 * **/
#include <civlc.cvh>
#include <stdio.h>
#include <stdlib.h>

$input int NUMDIM;
$input int NUMGP;
$input int NUMEL;
$assume(NUMDIM == 3);
$assume(NUMGP == 10);
$assume(NUMEL == 7040);

double dxm1[nx1][nx1], dxtm1[nx1][nx1];
void axi(double w[][], double u[][], double gxyz[][][], int n, int fel, int lel, int find, int lind);

void main(){

    int ldim =  NUMDIM;
    int nx1 = NUMGP, ny1 = NUMGP, nz1 = NUMGP, netl = NUMEL;
    int nxyz = nx1 * ny1 * nz1;
    double w[nelt][nxyz], u[netl][nxyz];
    double gxyz[nelt][nxyz][2*ldim];

    int n, thread, numth, i, j, k;
    int fel, lel, find, lind;
    int omp_get_thread_num, omp_get_num_threads;

    printf("nx1 = %d", nx1);
    printf("nelt = %d", nelt);

    n = nx1 * ny1 * nz1;
    
    w = 1.0;
    for(j = 0; j < nelt; j++){
        for(i = 0; i < n; i++){
            u(j, i) = 1.0 + 1.0/(1.0 * (i + j));
            for(k = 0; k < 6; k++){
                gxyz(j, i, k) = 1.0 + 1.0/(1.0 * i + 2.0 * j +3.0 * k);
            }
        }
    }

    for(i = 0; i < nx1; i++){
        for(j =0; j < nx1; j++){
            dxm1(i, j) = 1.0 + 1.0/(1.0*(i + 2*j));
            dxtm1(j, i) = 1.0 + 1.0/(1.0*(i+ 2*j));
        }
    }

    printf("Data initialized");

#pragma omp parallel default(shared) private(thread, numth, find, lind, fel, lel)
{
    thread = 0;
    numth = 1;
#ifdef _OPENMP
    thread = omp_get_thread_num();
    numth = omp_get_num_threads();
#endif

    if(numth < nelt){
        fel = (thread * nelt)/numth + 1;
        lel = ((thread + 1 )*nelt)/numth;
    }
    else{
        if(thread < nelt) {
            fel = thread + 1;
            lel = fel;
        }
        else{
            fel = nelt + 1;
            lel = nelt;
        }
    }

    find = (fel -1) * (nxyz) + 1;

    lind = lel * (nxyz);

    if(thread == 1) {
        printf("thread =%d", numth);
        printf("Calling axi()");
    }

    axi(w, u, gxyz, n, fel, lel, find, lind);
}
    printf("Simulation complete.");

}


