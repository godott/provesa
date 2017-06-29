void local_grad3(double ur[][][], double us[][][], double ut[][][], double u[][], int n, double D[][], double Dt[][]){

    int e, m1 = n + 1, m2 = m1 * m1, k;

    mxm(D, m1, u, m1, ur, m2);
    for(k = 0; k <= n; k++){
        mxm(u[k][0][0], m1, Dt, m1, us[k][0][0], m1);
    }
    mxm(u2, m2, D, m1, ut, m1);

    return;
}
