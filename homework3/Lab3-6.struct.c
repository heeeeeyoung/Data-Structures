#include <stdio.h>

struct student1 {           //구조체 student1 선언
    char lastName;          //char 형의 이름
    int studentId;          //int 형의 학번
    char grade;             //char 형의 성적
};


typedef struct {            //구조체 stuent2 선언
    char lastName;          //char 형의 이름    
    int studentId;          //int 형의 학번
    char grade;             //char 형의 성적
} student2;


int main() {
    struct student1 st1 = {'A', 100, 'A'};          //student1의 구조체 변수 st1 선언

    printf("st1.lastName = %c\n", st1.lastName);    //st1의 이름 출력
    printf("st1.studentId = %d\n", st1.studentId);  //st1의 학번 출력
    printf("st1.grade = %c\n", st1.grade);          //st1의 성적 출력

    student2 st2 = {'B', 200, 'B'};                 //student2의 구조체 변수 st2 선언

    printf("\nst2.lastName = %c\n", st2.lastName);  //st2의 이름 출력
    printf("st2.studentId = %d\n", st2.studentId);  //st2의 학번 출력
    printf("st2.grade = %c\n", st2.grade);          //st2의 성적 출력

    student2 st3;                                   //student2의 구조체 변수 st3 선언

    st3 = st2;                                      //st3의 값을 st2와 같게 한다.

    printf("\nst3.lastName = %c\n", st3.lastName);  //st3의 이름 출력
    printf("st3.studentId = %d\n", st3.studentId);  //st3의 학번 출력
    printf("st3.grade = %c\n", st3.grade);          //st3의 성적 출력

    /* equality test */
    if(st3.lastName == st2.lastName && st3.studentId==st2.studentId && st3.grade==st2.grade)    //만약 st3에 입력된 정보와 st2의 정보가 같다면
        printf("equal\n");                  //equal 프린트

    else                                    //같지 않다면
        printf("not equal\n");              //not equal 프린트

    return 0;
}
