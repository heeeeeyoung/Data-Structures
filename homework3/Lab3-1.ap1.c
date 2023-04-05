#include <stdio.h>
#include <stdlib.h>

void main() {
    int list[5];                                //int형의 크기가 5인 배열 list 선언
    int *plist[5] = {NULL,};                    //정수에 대한 다섯개의 포인터 배열 plist를 선언하고 초기화

    plist[0] = (int *)malloc(sizeof(int));      //plist에 int사이즈로 동적할당
   
    list[0] = 1;                                //배열 list의 0번째 인덱스의 값을 1로
    list[1] = 100;                              //배열 list의 1번째 인덱스의 값을 100으로 

    *plist[0] = 200;                            //포인터 plist의 0번 인덱스의 값을 200으로

    printf("list[0] = %d\n", list[0]);          //배열 list의 0번 인덱스의 값 출력
    printf("&list[0] = %p\n", &list[0]);        //배열 list의 0번 인덱스의 주소 출력
    printf("list = %p\n", list);                //배열 list의 주소값 출력
    printf("&list = %p\n", &list);              //배열 list의 주소값 출력

    printf("----------[Kimheeyoung]-------------[2021024037]-------\n");        //나의 학번과 이름 추가

    printf("list[1] = %d\n", list[1]);          //배열 list의 1번째 인덱스 값 출력
    printf("&list[1] = %p\n", &list[1]);        //배열 list의 1번째 인덱스의 주소 출력
    printf("*(list+1) = %d\n", *(list + 1));    //배열 list의 주소에 한 사이즈를 더한 곳의 인덱스 값 출력
    printf("list+1 = %p\n", list+1);            //배열 list의 주소에 한 사이즈를 더한 곳의 주소 출력

    printf("----------[Kimheeyoung]-------------[2021024037]-------\n");        //나의 학번과 이름 추가

    printf("*plist[0] = %d\n", *plist[0]);      //포인터 plist의 0번째에 들어있는 주소가 담고있는 값 출력
    printf("&plist[0] = %p\n", &plist[0]);      //포인터 plist의 0번째 인덱스의 주소 출력
    printf("&plist = %p\n", &plist);            //포인터 plist의 주소값 출력
    printf("plist = %p\n", plist);              //포인터 plist의 주소값 출력
    printf("plist[0] = %p\n", plist[0]);        //포인터 배열 plist의 0번째 값 출력
    printf("plist[1] = %p\n", plist[1]);        //포인터 배열 plist의 1번째 값 출력
    printf("plist[2] = %p\n", plist[2]);        //포인터 배열 plist의 2번째 값 출력
    printf("plist[3] = %p\n", plist[3]);        //포인터 배열 plist의 3번째 값 출력
    printf("plist[4] = %p\n", plist[4]);        //포인터 배열 plist의 4번째 값 출력

    free(plist[0]);                             //동적으로 할당해준 plist 해지
}

