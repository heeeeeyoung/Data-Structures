#include <stdio.h>
#include <stdlib.h>

void main() {
    int list[5];                            //int형의 크기가 5인 배열 list 선언
    int *plist[5];                          //정수에 대한 포인터 배열 다섯개를 선언

    list[0] = 10;                           //베열 list의 0번째 인덱스에 10 할당
    list[1] = 11;                           //배열 list의 1번째 인덱스에 11 할당

    plist[0] = (int*)malloc(sizeof(int));   //포인터 배열 plist에 int사이즈로 동적 할당

    printf("list[0] \t= %d\n", list[0]);        //배열 list의 0번째 인덱스의 값 출력           
    printf("list \t\t= %p\n", list);            //배열 list의 주소값 출력
    printf("&list[0] \t= %p\n", &list[0]);      //배열 list의 0번째 인덱스의 주소값 출력    
    printf("list + 0 \t= %p\n", list+0);        //배열 list의 주소값 출력
    printf("list + 1 \t= %p\n", list+1);        //배열 list의 시작에서 한 사이즈 증가한 곳의 주소값 출력
    printf("list + 2 \t= %p\n", list+2);        //배열 list의 시작에서 두번의 사이즈가 증가한 곳의 주소값 출력
    printf("list + 3 \t= %p\n", list+3);        //배열 list의 시작에서 세번의 사이즈가 증가한 곳의 주소값 출력
    printf("list + 4 \t= %p\n", list+4);        //배열 list의 시작에서 네번의 사이즈가 증가한 곳의 주소값 출력
    printf("&list[4] \t= %p\n", &list[4]);      //배열 list의 4번째 인덱스의 주소값 출력

    free(plist[0]);                             //동적 할당 해지
}
