#include <stdio.h>

int main() {
    char charType;                                                                           // char 타입의 변수 charType 선언
    int integerType;                                                                         // int 타입의 변수 integerType 선언
    float floatType;                                                                          // float 타입의 변수 floatType 선언
    double doubleType;                                                                   // double 타입의 변수 doubleType 선언

    printf("Size of char : %ld byte \n", sizeof(charType));                    // char 타입으로 선언된 변수 charType의 크기인 1byte 출력
    printf("Size of int : %ld bytes \n", sizeof(integerType));                 // int 타입으로 선언된 변수 integerType의 크기인 4byte 출력
    printf("Size of float : %ld bytes \n", sizeof(floatType));                 // float 타입으로 선언된 변수 floatType의 크기인 4byte 출력
    printf("Size of double : %ld bytes \n", sizeof(doubleType));               // double 타입으로 선언된 변수 doubleType 의 크기인 8byte 출력

    printf("----[Kimheeyoung]---------[2021024037]---------\n");       // 나의 이름과 학번 출력

    
    printf("Size of char : %ld byte \n", sizeof(char));                        // char 타입의 크기인 1byte 출력
    printf("Size of int : %ld bytes \n", sizeof(int));                         // int 타입의 크기인 4byte 출력
    printf("Size of float : %ld bytes \n", sizeof(float));                     // float 타입의 크기인 4byte 출력
    printf("Size of double : %ld bytes \n", sizeof(double));                   // double 타입의 크기인 8byte 출력

    printf("----[Kimheeyoung]---------[2021024037]---------\n");       // 나의 이름과 학번 출력

    
    printf("Size of char *: %ld byte \n", sizeof(char*));                      // char * 타입의 크기인 8byte 출력
    printf("Size of int *: %ld bytes \n", sizeof(int*));                       // int * 타입의 크기인 8byte 출력
    printf("Size of float *: %ld bytes \n", sizeof(float*));                   // float * 타입의 크기인 8byte 출력
    printf("Size of double *: %ld bytes \n", sizeof(double*));                 // double * 타입의 크기인 8byte 출력

    //printf("address of charType : %ld \n", &charType);
    //printf("address of integerType : %ld \n", &integerType);
    //printf("address of floatType : %ld \n", &floatType);
    //printf("address of doubleType : %ld \n", &doubleType);

    return 0;                                                      // 포인터 타입의 경우 주소를 저장하기 때문에 8byte가 출력됨
}
