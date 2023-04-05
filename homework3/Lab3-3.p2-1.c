#include <stdio.h>
#define MAX_SIZE 100                    //MAX_SIZE는 100

float sum1(float list[], int);          //함수 sum1 정의
float sum2(float *list, int);           //함수 sum2 정의    
float sum3(int n, float *list);         //함수 sum3 정의
float input[MAX_SIZE], answer;          //크기가 100인 실수형 배열 input과, 실수형 변수 answer 선언

int i;                                  //int형의 변수 i 정의

void main(void) {
    for(i=0; i < MAX_SIZE; i++)         //i가 0부터 MAX_SIZE까지 
        input[i] = i;                   //배열 input의 i번째 인덱스에 i의 값을 대입

    /* for checking call by reference */
    printf("----------[Kimheeyoung]-------------[2021024037]-------\n");        //나의 학번과 이름 출력
    printf(" sum1(input, MAX_SIZE) \n");                                        //해당 문구 출력
    printf("----------[Kimheeyoung]-------------[2021024037]-------\n");        //나의 학번과 이름 출력
    printf("input \t= %p\n", input);                                            //배열 input의 주소값 출력

    answer = sum1(input, MAX_SIZE);                                             //sum1 함수의 매개변수로 input과 MAX_SIZE 를 이용하여 실행하고, return되는 값을 answer에 대입
    printf("The sum is: %f\n\n", answer);                                       //sum1 함수를 실행한 결과인 answer값 출력    

    printf("----------[Kimheeyoung]-------------[2021024037]-------\n");        //나의 학번과 이름 출력
    printf(" sum2(input, MAX_SIZE) \n");                                        //해당 문구 출력    
    printf("----------[Kimheeyoung]-------------[2021024037]-------\n");        //나의 학번과 이름 출력    
    printf("input \t= %p\n", input);                                            //배열 input의 주소값 출력

    answer = sum2(input, MAX_SIZE);                                             //sum2 함수의 매개변수로 input과 MAX_SIZE를 이용하여 실행하고, return되는 값을 answer에 대입
    printf("The sum is: %f\n\n", answer);                                       //sum2 함수를 실행한 결과인 answer값 출력       
    
    printf("----------[Kimheeyoung]-------------[2021024037]-------\n");        //나의 학번과 이름 츨력
    printf(" sum3(MAX_SIZE, input) \n");                                        //해당 문구 출력        
    printf("----------[Kimheeyoung]-------------[2021024037]-------\n");        //나의 학번과 이름 출력
    printf("input \t= %p\n", input);                                            //배열 input의 주소값 출력

    answer = sum3(MAX_SIZE, input);                                             //sum3 함수의 매개변수로 MAX_SIZE와 input을 이용하여 실행하고, return되는 값을 answer에 대입
    printf("The sum is: %f\n\n", answer);                                       //sum3 함수를 실행한 결과인 answer값 출력
}


float sum1(float list[], int n) {           //함수 sum1은 매개변수로 실수형 배열과, 정수형 변수를 받음                                   
    printf("list \t= %p\n", list);          //매개변수로 받은 배열 input의 주소값 출력
    printf("&list \t= %p\n\n", &list);      //배열 list의 주소값 출력

    int i;                                  //정수형 변수 i선언    
    float tempsum = 0;                      //실수형 변수 tempsum 선언        

    for(i = 0; i < n; i++)                  //i가 0부터 n일 동안
        tempsum += list[i];                 //list의 i번째 값들을 모두 더해 tempsum에 대입

    return tempsum;                         //tempsum 값 return
}


float sum2(float *list, int n) {            //함수 sum2는 매개변수로 실수형 포인터와, 정수형 변수를 받음
    printf("list \t= %p\n", list);          //매개변수로 받은 배열 input의 주소값 출력
    printf("&list \t= %p\n\n", &list);      //변수 list의 주소값 출력

    int i;                                  //정수형 변수 i선언
    float tempsum = 0;                      //실수형 변수 tempsum 선언

    for(i = 0; i < n; i++)                  //i가 0부터 n일동안
        tempsum += *(list +i);              //list에서 i 사이즈 만큼 증가한 인덱스의 값을 모두 더해 tempsum에 대입

    return tempsum;                         //tempsum 값 return
}



/* stack variable reuse test */
float sum3(int n, float *list) {            //함수 sum3는 매개변수로 정수형 변수와, 실수형 포인터를 받음
    printf("list \t= %p\n", list);          //매개변수로 받은 배열 input의 주소값 출력    
    printf("&list\t= %p\n\n", &list);       //변수 list의 주소값 출력

    int i;                                  //정수형 변수 i선언    
    float tempsum = 0;                      //실수형 변수 tempsum 선언

    for(i = 0; i < n; i++)                  //i가 0부터 n까지
        tempsum += *(list +i);              //list에서 i 사이즈 만큼 증가한 인덱스의 값을 모두 더해 tempsum에 대입

    return tempsum;                         //tempsum 값 return
}