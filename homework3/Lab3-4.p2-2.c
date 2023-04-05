#include <stdio.h>

void print_one(int *ptr, int rows);         //print_one 함수 선언

int main() {
    int one[] = {0, 1, 2, 3, 4};            //정수형 배열 one 선언

    printf("one = %p\n", one);              //배열 one의 주소값 출력
    printf("&one = %p\n", &one);            //배열 one의 주소값 출력
    printf("&one[0] = %p\n", &one[0]);      //배열 one의 0번째 인덱스의 주소값 출력
    printf("\n");                           //print

    printf("----------[Kimheeyoung]-------------[2021024037]-------\n");        //나의 학번과 이름 출력
    printf(" print_one(&one[0], 5) \n");                                        //해당 문구 출력
    printf("----------[Kimheeyoung]-------------[2021024037]-------\n");        //나의 학번과 이름 출력
    print_one(&one[0], 5);                                                      //매개변수로 배열 one의 주소와, 5를 갖는 함수 print_one 실행

    printf("----------[Kimheeyoung]-------------[2021024037]-------\n");        //나의 학번과 이름 출력
    printf(" print_one(one, 5) \n");                                            //해당 문구 출력    
    printf("----------[Kimheeyoung]-------------[2021024037]-------\n");        //나의 학번과 이름 출력
    print_one(one, 5);                                                          //매개변수로 배열 one의 주소와, 5를 갖는 함수 print_one 실행

    return 0;
}


void print_one(int *ptr, int rows) {                                            //매개변수로 정수형 포인터 변수와 정수형 변수를 갖는 함수 print_one 선언
    /* print out a one-dimensional array using a pointer */
    int i;                                                         //변수 i 선언

    printf ("Address \t Contents\n");                              //해당 문구 출력 

    for (i = 0; i < rows; i++)                                     //i가 0부터 rows일때      
        printf("%p \t %5d\n", ptr + i, *(ptr + i));                //매개변수로 받은 배열 one의 주소에 i사이즈 만큼 증가시킨 주소와, 해당 주소의 인덱스 값 출력 

    printf("\n");                                                  //print 
}
