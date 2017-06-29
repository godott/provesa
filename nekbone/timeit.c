/****
 * This is a C implementation of timeit.f
 * **/

//#include <civlc.cvh>
#include <stdio.h>
#include <stdlib.h>
#include "timeit.h"
//Global variables

//Function declarations
void axi(double **w, double **u, double ***gxyz, int n, int fel, int lel, int find, int lind);
void allocate_2d(double **a, int d1, int d2);
void allocate_3d(double ***a, int d1, int d2, int d3);
void free_2d(double **a, int d1, int d2);
void free_3d(double ***a, int d1, int d2, int d3);

void main(){
    int ldim = NUMDIM, nx1 = NUMGP, ny1 = NUMGP, nz1 = NUMGP, nelt = NUMEL, n = nx1 * ny1 * nz1;

    int thread, numth, i, j, k;
    int fel, lel, find, lind;
    int omp_get_thread_num, omp_get_num_threads;

    double **w, **u;
    double ***gxyz;
    double dxm1[NUMGP][NUMGP], dxtm1[NUMGP][NUMGP];

    allocate_2d(w, nelt, n);
    allocate_2d(u, nelt, n);
    allocate_3d(gxyz, nelt, n, 2*ldim);

    printf("nx1 = %d\n", nx1);
    printf("nelt = %d\n", nelt);
    for(i = 0; i < nelt; i++){
        for(j = 0; j < n; j++){
            w[i][j] = 1.0;
            u[i][j] = 1.0 + 1.0/(1.0 * (i + j));
            for(k = 0; k < 2*ldim; k++){
                gxyz[i][j][k] = 1.0 + 1.0/(1.0 * j + 2.0 * i +3.0 * k);
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

    free_2d(w, nelt, n);
    free_2d(u, nelt, n);
    free_3d(gxyz, nelt, n, 2*ldim);
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

void allocate_2d(double **a, int d1, int d2){
    a = (double **) malloc(sizeof(double *) * d1);
    for(int i = 0; i< d1; i++){
        a[i] = (double *) malloc(sizeof(double) * d2);
    }
}

void free_2d(double **a, int d1, int d2){
    for(int i = 0; i< d1; i++){
        free(a[i]);
    }
    free(a);
}

void allocate_3d(double ***a, int d1, int d2, int d3){
    a =(double ***) malloc(sizeof(double **) * d1);
    for(int i = 0; i< d1; i++){
        a[i] = (double **) malloc(sizeof(double *) * d2);
        for(int j = 0; j< d2; i++){
            a[i][j] = (double *) malloc(sizeof(double) * d3);
        }
    }
}

void free_3d(double ***a, int d1, int d2, int d3){
    for(int i = 0; i< d1; i++){
        for(int j = 0; j < d2; j++){
            free(a[i][j]);
        }
    }
    for(int i = 0; i < d1; i++){
            free(a[i]); 
    }
    free(a);
}
