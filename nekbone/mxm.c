void mxm(double a[][], int n1, double b[][], int n2, double c[][], int n3){
    int i, j, k;
    for(j = 1; j <= n3; j++){
        for(i = 1; i <= n1; i++){
            c[j][i] = 0.0;
            for(k = 1; k <= n2; k++){
                c[j][i] = c[j][i] + a[k][i] * b[j][k];
            }
        }
    }
    
    return;
}
