void MXM44_0(double A[][], int N1, double B[][], int N2, double C[][], int N3){
    int i, j, k;
    double s;
    #pragma omp parallel for private(k,i,j,s)
    for (j = 0; j < N3; j++){
        for (i = 0; i < N1; i++){
            s = 0.0f;
            for (k = 0; k < N2; k++){
                s = s + A[k][i]*B[j][k]; 
            }
            C[j][i] = s;
        }
    }
    return;
}
