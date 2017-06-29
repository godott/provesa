#ifndef TIMEIT_H
#define TIMEIT_H

#define NUMDIM 3
#define NUMGP 10
#define NUMEL 7040

/*Civl pragma
$input int NUMDIM;
$input int NUMGP;
$input int NUMEL;
$assume(NUMDIM == 3);
$assume(NUMGP == 10);
$assume(NUMEL == 7040);
*/

//Global variables
extern double dxm1[NUMGP][NUMGP], dxtm1[NUMGP][NUMGP];

extern int ldim, nx1, ny1, nz1, nelt, n;

#endif
