#include<stdio.h>
#include<stdlib.h>

void main() {
    int **x;        //이중 포인터 변수 x 선언

    printf("sizeof(x) = %lu\n", sizeof(x));     //x의 크기 출력
    printf("sizeof(*x) = %lu\n", sizeof(*x));   //포인터 x의 크기 출력
    printf("sizeof(**x) = %lu\n", sizeof(**x)); //이중 포인터 x의 크기 출력
}