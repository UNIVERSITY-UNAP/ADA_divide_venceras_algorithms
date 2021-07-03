void AgregarMatrices(double A[][TAM], double B[][TAM], double C[][TAM], int N){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            C[i][j]=A[i][j]+B[i][j];
        }
    }
}

void SubstraerMatriz(double A[][TAM], double B[][TAM], double C[][TAM], int N){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            C[i][j]=A[i][j]-B[i][j];
        }
    }
}

void AlgoritStrassen(double A[][TAM], double B[][TAM], double C[][TAM], int N){
    if(N==1){
        C[0][0]=A[0][0] * B[0][0];
        return;
    }
    else{
        int Divide = (int)(N/2);

        double A11[TAM][TAM], A12[TAM][TAM], A21[TAM][TAM], A22[TAM][TAM];
        double B11[TAM][TAM], B12[TAM][TAM], B21[TAM][TAM], B22[TAM][TAM];
        double C11[TAM][TAM], C12[TAM][TAM], C21[TAM][TAM], C22[TAM][TAM];
        double P1[TAM][TAM], P2[TAM][TAM], P3[TAM][TAM], P4[TAM][TAM], P5[TAM][TAM], P6[TAM][TAM], P7[TAM][TAM];
        double AResult[TAM][TAM], BResult[TAM][TAM];

        for(int i=0; i<Divide; i++){
            for(int j=0; j<Divide; j++){
                A11[i][j]=A[i][j];
                A12[i][j]=A[i][j+Divide];
                A21[i][j]=A[i+Divide][j];
                A22[i][j]=A[i+Divide][j+Divide];

                B11[i][j]=B[i][j];
                B12[i][j]=B[i][j+Divide];
                B21[i][j]=B[i+Divide][j];
                B22[i][j]=B[i+Divide][j+Divide];
            }
        }

        AgregarMatrices(A11, A22, AResult, Divide);
        AgregarMatrices(B11, B22, BResult, Divide);
        AlgoritStrassen(AResult, BResult, P1, Divide);

        AgregarMatrices(A21, A22, AResult, Divide);
        AlgoritStrassen(AResult, B11, P2, Divide);

        SubstraerMatriz(B12, B22, BResult, Divide);
        AlgoritStrassen(A11, BResult, P3, Divide);

        SubstraerMatriz(B21, B11, BResult, Divide);
        AlgoritStrassen(A22, BResult, P4, Divide);

        AgregarMatrices(A11, A12, AResult, Divide);
        AlgoritStrassen(AResult, B22, P5, Divide);

        SubstraerMatriz(A21, A11, AResult, Divide);
        AgregarMatrices(B11, B12, BResult, Divide);
        AlgoritStrassen(AResult, BResult, P6, Divide);

        SubstraerMatriz(A12, A22, AResult, Divide);
        AgregarMatrices(B21, B22, BResult, Divide);
        AlgoritStrassen(AResult, BResult, P7, Divide);

        AgregarMatrices(P3, P5, C12, Divide);
        AgregarMatrices(P2, P4, C21, Divide);

        AgregarMatrices(P1, P4, AResult, Divide);
        AgregarMatrices(AResult, P7, BResult, Divide);
        SubstraerMatriz(BResult, P5, C11, Divide);

        AgregarMatrices(P1, P3, AResult, Divide);
        AgregarMatrices(AResult, P6, BResult, Divide);
        SubstraerMatriz(BResult, P2, C22, Divide);

        for(int i=0; i<Divide; i++){
            for(int j=0; j<Divide; j++){
                C[i][j]=C11[i][j];
                C[i][j+Divide]=C12[i][j];
                C[i+Divide][j]=C21[i][j];
                C[i+Divide][j+Divide]=C22[i][j];
            }
        }
    }
}
