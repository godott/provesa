#ifndef TIMEIT_H
#define TIMEIT_H

#include <civlc.cvh>
#include <stdio.h>
#include <stdlib.h>

$input int NUMDIM;
$input int NUMGP;
$input int NUMEL;
$assume(NUMDIM == 3);
$assume(NUMGP == 2);
$assume(NUMEL == 2);

$output double my_out[NUMEL][NUMGP*NUMGP*NUMGP];
extern int ldim;
extern int nx1;
extern int ny1;
extern int nz1;
extern int nelt;
extern int n;

#endif
