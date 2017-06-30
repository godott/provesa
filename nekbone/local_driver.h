#ifndef LOCAL_DR_H 
#define LOCAL_DR_H

#define NUMGP 10

/*Civl pragma
$input int NUMGP;
$assume(NUMGP == 10);
*/

//Global variables
extern double dxm1[NUMGP][NUMGP], dxtm1[NUMGP][NUMGP];

extern int ldim, nx1, ny1, nz1, nelt, n;
#endif
