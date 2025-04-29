#include <stdio.h>

#define N 2 

void standared_multiply(int A[N][N], int B[N][N], int C[N][N]){
    for (int i = 0; i<N; i++){
        for (int j = 0; j<N; j++){
            C[i][j] = 0;
            for (int k=0; k<N; k++){
                C[i][j] += A[i][k] * B[k][j];  
            }
        }
    }
}

void print_matrix(int C[N][N]){
    for (int i = 0; i<N; i++){
        for (int j = 0; j<N; j++){
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int A[N][N] = {{1, 2}, {3, 4}};
    int B[N][N] = {{5, 6}, {7, 8}};
    int C[N][N];

    standared_multiply(A, B, C);
    printf("The product of the two matrices is:\n");
    print_matrix(C);
    printf("The time complexity of this algorithm is O(n^3)\n");
return 0;
}