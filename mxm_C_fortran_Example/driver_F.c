#include <civlc.cvh>
#include <stdio.h>

void MXM44_0(double a[][], int n1, double b[][], int n2, double c[][], int n3);

$input int mSize;
$assume(0 < mSize && mSize < 11);

void main(){
    int n = mSize;
    double a[n][n], b[n][n], c[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) {
            a[i][j] = 1.0*(i + j);
            b[i][j] = 1.0*(i - j);
            c[i][j] = 0.0;
        }
    }

    MXM44_0(a, n, b, n, c, n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) {
            printf("c[%d][%d]: %d", i, j, c[i][j]);
        }
    }
}
