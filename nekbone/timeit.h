#ifndef TIMEIT_H
#define TIMEIT_H

#include <civlc.cvh>
#include <stdio.h>
#include <stdlib.h>

$input int NUMDIM;
$input int NUMGP;
$input int NUMEL;
$assume(NUMDIM == 3);
$assume(NUMGP == 3);
$assume(NUMEL == 16);

extern ldim;
extern nx1;
extern ny1;
extern nz1;
extern nelt;
extern n;

#endif
