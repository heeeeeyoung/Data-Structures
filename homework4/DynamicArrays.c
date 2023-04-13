#include <stdio.h>
#include <stdlib.h>

int** matrixA = NULL;		//기본행렬 A
int** matrixB = NULL;			//기본행렬 B

int** result1 = NULL;			//addition 함수 결과값을 넣을 행렬
int** result2 = NULL;			//subtract 함수 결과값을 넣을 행렬
int** result3 = NULL;			//transpose 함수 결과값을 넣을 행렬
int** result4 = NULL;			//multipy 함수 결과값을 넣을 행렬

int rowA = 0;					//행렬 A의 행의 수
int colA = 0;					//행렬 A의 열의 수
int rowB = 0;					//행렬 B의 행의 수
int colB = 0;						//행렬 B의 열의 수


//함수 선언
void print_matrix(int**, int, int);
void addition_matrix();
void subtract_matrix();
void transpose_matrix();
void multiply_matrix();
void free_matrix(int**, int);



int main() {
    //사용자로부터 행렬 A의 크기를 입력받음
    printf("matrixA 의 크기 \n");       
    printf("row : ");
    scanf_s("%d", &rowA);
    printf("col : ");
    scanf_s("%d", &colA);
    printf("\n");

    //사용자로부터 행렬 B의 크기를 입력받음
    printf("matrixB 의 크기 \n");
    printf("row : ");
    scanf_s("%d", &rowB);
    printf("col : ");
    scanf_s("%d", &colB);
    printf("\n\n");


    //행렬 A를 동적할당
    matrixA = (int**)malloc(sizeof(int*) * rowA);           //행을 먼저 할당

    for (int i = 0; i < rowA; i++) {
        matrixA[i] = (int*)malloc(sizeof(int) * colA);          //각각의 열을 할당
    }

    //행렬 B를 동적할당
    matrixB = (int**)malloc(sizeof(int*) * rowB);           //행을 먼저 할당

    for (int i = 0; i < rowB; i++) {
        matrixB[i] = (int*)malloc(sizeof(int) * colB);          //각각의 열을 할당
    }


    //행렬 A에 1부터 9까지의 숫자를 차례대로 넣음
    int number = 1;         //행렬에 숫자를 넣어주기위한 변수 선언
   
    for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < colA; j++) {
            matrixA[i][j] = number;
            number++;
        }
    }

    //행렬 B에 1부터 9까지의 숫자를 차례대로 넣음
    number = 1;         //행렬에 숫자를 넣어주기 위한 변수 선언
    
    for (int i = 0; i < rowB; i++) {
        for (int j = 0; j < colB; j++) {
            matrixB[i][j] = number;
            number++;
        }
    }

    printf("matrixA\n");               //행렬 A출력
    print_matrix(matrixA, rowA, colA);       //print_matrix 함수 이용
    printf("matrixB\n");               //행렬 B출력
    print_matrix(matrixB, rowB, colB);       //print_matrix 함수 이용

    addition_matrix();                           //addition_matrix 함수 실행
    subtract_matrix();                           //subtradt_matrix 함수 실행
    transpose_matrix();                         //transpose_matrix 함수 실행
    multiply_matrix();                          //multipy_matirx 함수 실행

    free_matrix(matrixA, rowA);             //matrixA의 동적할당 해제
    free_matrix(matrixB, rowB);             //matrixB의 동적할당 해제
    free_matrix(result1, rowA);      //result1의 동적할당 해제
    free_matrix(result2, rowA);     //result2의 동적할당 해제
    free_matrix(result3, rowA);     //result3의 동적할당 해제
    free_matrix(result4, rowA);     //result4의 동적할당 해제

    return 0;
}

void print_matrix(int **matrix, int row, int col) {         //행렬을 출력하는 함수 print_matrix
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("  %d  ", matrix[i][j]);
        }

        printf("\n");
    }
    printf("------------------[Kimheeyoung]---------[2021024037]----------");
    printf("\n\n");
}


void addition_matrix() {                                        //두개의 행렬을 더하는 함수 addtion_matrix
    if (rowA != rowB || colA != colB) {                      //두 행렬의 크기가 맞지 않을 경우 에러 메세지 출력
        printf("\n두 행렬의 크기가 맞지 않아 계산이 불가능합니다. \n\n");
    }

    else {                                                          //두 행렬의 크기가 맞을 경우 연산 실행
        result1 = (int**)malloc(sizeof(int*) * rowA);

        for (int i = 0; i < rowA; i++) {
            result1[i] = (int*)malloc(sizeof(int) * colA);          //result1의 동적할당
        }

        for (int i = 0; i < rowA; i++) {
            for (int j = 0; j < colA; j++) {
                result1[i][j] = matrixA[i][j] + matrixB[i][j];
            }
        }

        printf("matrixA + matrixB = \n");                     //연산 결과를 print_matrix 를 이용하여 출력
        print_matrix(result1, rowA, colA);
    }
}


void subtract_matrix() {                                                    //두개의 행렬을 빼는 subtract_matrix 함수
    if (rowA != rowB || colA != colB) {                                  //두 행렬의 크기가 맞지 않을 경우 에러 메세지 출력
        printf("\n두 행렬의 크기가 맞지 않아 계산이 불가능합니다. \n\n");
    }

    else {                                                                      //두 행렬의 크기가 맞을 경우 연산 실행
        result2 = (int**)malloc(sizeof(int*) * rowA);

        for (int i = 0; i < rowA; i++) {
            result2[i] = (int*)malloc(sizeof(int) * colA);          //result2의 동적할당
        }

        for (int i = 0; i < rowA; i++) {
            for (int j = 0; j < colA; j++) {
                result2[i][j] = matrixA[i][j] - matrixB[i][j];
            }
        }

        printf("matrixA - matrixB =\n");                        //연산 결과를 print_matrix를 이용하여 출력
        print_matrix(result2, rowA, colA);
    }
}

    
void transpose_matrix() {                                                   //하나의 행렬을 전치행렬로 변환시키는 transpose_matrix 함수
    result3 = (int**)malloc(sizeof(int*) * rowA);                  //result3의 동적할당

    for (int i = 0; i < colA; i++) {
        result3[i] = (int*)malloc(sizeof(int) * colA);                      
    }

    for (int i = 0; i < colA; i++) {
        for (int j = 0; j < rowA; j++) {
            result3[i][j] = matrixA[j][i];                                      //matrixA의 전치행렬을 만드려면, 행과 열을 바꾸어 저장해주어야함
        }
    }

    printf("transposed matrix of matrixA = \n");            //연산 결과를 print_matrix를 이용하여 출력
    print_matrix(result3, rowA, colB);
}

void multiply_matrix() {                                                    //두개의 행렬을 곱하는 multiply_matrix 함수
    if (colA != rowB) {                                                      //두 행렬의 행의 수과 열의 수가 맞지 않을 경우 에러 메세지 출력       
        printf("\n두 행렬의 크기가 맞지 않아 계산이 불가능합니다. \n\n");
    }

    else {
        result4 = (int**)malloc(sizeof(int*) * rowA);               //result4의 동적할당

        for (int i = 0; i < rowA; i++) {
            result4[i] = (int*)malloc(sizeof(int) * colB);
        }

        int sum;

        for (int i = 0; i < rowA; i++) {
            for (int j = 0; j < colB; j++) {
                sum = 0;

                for (int k = 0; k < colA; k++) {
                    sum = sum + matrixA[i][k] * matrixB[k][j];          //행렬의 곱셈 원리를 이용하여 i, j, k 세가지 변수를 두고 계산
                }
                result4[i][j] = sum;
            }
        }

        printf("matrixA * matrixB = \n");                        //연산 결과를 print_matrix를 이용하여 출력
        print_matrix(result4, rowA, colB);
    }
}

void free_matrix(int** matrix, int row) {                                 //동적 할당된 행렬을 해제해주는 free_matrix 함수
    for (int i = 0; i < row; i++) {
        free(matrix[i]);                                                    //각각의 열을 먼저 해제하고
    }
        
    free(matrix);                                                         //행렬의 행 해제  
}

