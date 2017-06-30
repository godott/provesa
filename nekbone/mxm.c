void mxm(void *a, int n1, void *b, int n2, void *c, int n3){
    int i, j, k;
    double ** aa =(double **) a;
    double ** bb =(double **) b;
    double ** cc =(double **) c;
    for(j = 1; j <= n3; j++){
        for(i = 1; i <= n1; i++){
            cc[j][i] = 0.0;
            for(k = 1; k <= n2; k++){
                cc[j][i] = cc[j][i] + aa[k][i] * bb[j][k];
            }
        }
    }
    
    return;
}
