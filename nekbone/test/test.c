/****
 * This is a C implementation of timeit.f
 * **/

#define NUMDIM 3
#define NUMGP 10
#define NUMEL 7040
//#include <civlc.cvh>
#include <stdio.h>
#include <stdlib.h>
#include "test.h"
/*
//Civl pragma
$input int NUMDIM;
$input int NUMGP;
$input int NUMEL;
$assume(NUMDIM == 3);
$assume(NUMGP == 10);
$assume(NUMEL == 7040);
*/

//Global variables

extern double dxm1[NUMGP][NUMGP], dxtm1[NUMGP][NUMGP];  

//Function declarations
void axi(double **w, double **u, double ***gxyz, int n, int fel, int lel, int find, int lind);

void main(){
    int ldim = 3, nx1 = 10, ny1 = 10, nz1 = 10, nelt = 70, n = nx1 * ny1 * nz1;

    double w[nelt][n], u[nelt][n];
    double gxyz[nelt][n][2*ldim];

    int thread, numth, i, j, k;
    int fel, lel, find, lind;
    int omp_get_thread_num, omp_get_num_threads;

    printf("nx1 = %d\n", nx1);
    printf("nelt = %d\n", nelt);
    for(j = 0; j < nelt; j++){
        for(i = 0; i < n; i++){
            w[j][i] = 1.0;
            u[j][i] = 1.0 + 1.0/(1.0 * (i + j));
            for(k = 0; k < 6; k++){
                gxyz[j][i][k] = 1.0 + 1.0/(1.0 * i + 2.0 * j +3.0 * k);
            }
        }
    }

    for(i = 0; i < nx1; i++){
        for(j =0; j < nx1; j++){
            dxm1[i][j] = 1.0 + 1.0/(1.0*(i + 2*j));
            dxtm1[j][i] = 1.0 + 1.0/(1.0*(i+ 2*j));
        }
    }
    printf("Data initialized");
//    printf("%p", *w);
/*
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

    find = (fel -1) * n + 1;

    lind = lel * n;

    if(thread == 1) {
        printf("thread =%d", numth);
        printf("Calling axi()");
    }

    axi(w, u, gxyz, n, fel, lel, find, lind);
}
    printf("Simulation complete.");
*/
}


