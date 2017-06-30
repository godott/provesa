#include "timeit.h"

void mxm( void * a, int n1, void * b, int n2, void * c, int n3);
void local_grad3(double ur[n], double us[n], double ut[n], double **u, int ni, double D[nx1][nx1], double Dt[nx1][nx1]){
       int m1 = ni + 1;
       int m2 = m1 * m1;
       int k;
    
       mxm((void *)D, m1, (void *)(*u), m1, (void *)ur, m2);

       for(k = 0; k <= ni; k++){
            mxm((void *)(*(u+k*(ni + 1)*(ni + 1))), m1,(void*) Dt, m1, (void *)(us + k * (ni +1) *(ni + 1)), m1);
       }

        mxm((void *)(*u), m2,(void *)Dt, m1,(void *)ut, m1);

        return;
    
}
