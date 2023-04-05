#include <stdio.h>

struct student {                //stdent 구조체 선언
    char lastName[13];        /* 13 bytes, char 형의 이름*/ 
    int studentId;            /* 4 bytes, int 형의 학번 */
    short grade;              /* 2 bytes, short 형의 성적*/
};


int main() {
    struct student pst;     //student 구조체 변수 pst선언

    printf("size of student = %ld\n", sizeof(struct student));      //구조체 student의 크기 출력 (padding 으로 인해 13byte+4byte+2byte 한 값보다 크기가 큼)
    printf("size of int = %ld\n", sizeof(int));                     //int 형의 크기 출력
    printf("size of short = %ld\n", sizeof(short));                 //short 형의 크기 출력

    return 0;
}
