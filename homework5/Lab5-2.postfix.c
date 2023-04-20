#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define MAX_STACK_SIZE 10               
#define MAX_EXPRESSION_SIZE 20

/* stack 내에서 우선순위는 내림차순, lparen = 0 가장 낮음 */
typedef enum {
    lparen = 0,                 //1번째_왼쪽 괄호 '('
    rparen = 9,                 //7번째_오른쪽 괄호 ')'
    times = 7,                  //6번째_곱하기 '*'
    divide = 6,                 //5번째_나누기 '/'
    plus = 5,                    //4번째_더하기 '+'
    minus = 4,                 //3번째_빼기 '-'
    operand = 1              //2번째_피연산자 'operand'
} precedence;                //typedof enum을 이용하여 precedence로 정의


//사용될 변수와 함수 정의
char infixExp[MAX_EXPRESSION_SIZE];
char postfixExp[MAX_EXPRESSION_SIZE];
char postfixStack[MAX_STACK_SIZE];

int evalStack[MAX_STACK_SIZE];
int postfixStackTop = -1;
int evalStackTop = -1;
int evalResult = 0;

void postfixPush(char x);
char postfixPop();
void evalPush(int x);
int evalPop();
void getInfix();

precedence getToken(char symbol);
precedence getPriority(char x);

void charCat(char*);
void toPostfix();
void debug();
void reset();
void evaluation();


int main() {
    char command;           //char 형의 변수 command 선언

    do {                    //command가 q나 Q가 아니면 반복 실행
        printf("--------[2021024037]-----------[Kimheeyoung]------------\n");       //나의 학번과 이름 출력
        printf(" Infix to Postfix, then Evaluation\n");                                       //해당 문구 출력
        printf("--------[2021024037]-----------[Kimheeyoung]------------\n");       //나의 학번과 이름 출력
        printf(" Infix=i, Postfix=p, Eval=e, Debug=d, Reset=r,Quit=q \n");          //해당 문구 출력
        printf("--------[2021024037]-----------[Kimheeyoung]------------\n");       //나의 학번과 이름 출력
        
        printf("Command = ");               //사용자로부터 command 값을 입력받음
        scanf_s(" %c", &command);

        switch (command) {            //comman의 값에 따라 
            case 'i': case 'I':              //i나 I를 입력받았을 경우
                getInfix();                 //getlnfix함수 실행         
                break;                     //break

            case 'p': case 'P':            //p나 P를 입력받았을 경우
                toPostfix();                //toPostfix함수 실행
                break;                      //break

            case 'e': case 'E':             //e나 E를 입력받았을 경우
                evaluation();               //evaluation 함수 실행
                break;                      //break

            case 'd': case 'D':             //d나 D를 입력받았을 경우
                debug();                    //debug 함수 실행
                break;                      //break

            case 'r': case 'R':             //r이나 R을 입력받았을 경우
                reset();                     //reset 함수 실행
                break;                      //break

            case 'q': case 'Q':            //q나 Q를 입력받았을 경우
                break;                      //break
        
            default:                  //그 외의 값을 입력받았을 경우
                printf("\n >>>>> Concentration!! <<<<<\n");         //해당 문구 출력
                break;                      //break
        }

    } while (command != 'q' && command != 'Q');             //command가 q나 Q가 될 때 까지 반복

    return 1;   
}


void postfixPush(char x) {                  //postfixStack에 넣는 함수
    postfixStack[++postfixStackTop] = x;        //postStack[++postStackTop]에 x의 값을 대입
}


char postfixPop() {                 //postfixStack에서 하나를 꺼내를 함수
    char x;                     //char 형 변수 x 선언    

    if (postfixStackTop == -1)          //만약 postfixStackTop의 값이 -1일 경우 (비어있을 경우)
        return '\0';                         //NULL 값 리턴

    else {                                      //postfixStack이 비어있지 않은 경우
        x = postfixStack[postfixStackTop--];        //x에 postfixStack[postfixStackTop--]대입
    }

    return x;                   //x 리턴
}


void evalPush(int x) {              //evalStack에 하나를 넣는 함수
    evalStack[++evalStackTop] = x;              //evalStack[++evalStackTop]에 x의 값을 대입
}


int evalPop() {                 //evalStack에서 하나를 꺼내는 함수
    if (evalStackTop == -1)             //만약 evalStackTop이 -1일 경우 (비어있을 경우)
        return -1;                  //-1 리턴

    else                            //evalStack이 비어있지 않은 경우
        return evalStack[evalStackTop--];               //evalStack[evalStackTop--] 리턴
}


void getInfix() {                       //사용자로부터 infix값을 입력받는 함수
    printf("Type the expression >>> ");             //해당 문구 출력
    scanf_s("%s", infixExp);                    //사용자로부터 infixExp값을 입력받고 저장
}


precedence getToken(char symbol) {                  //sysbol에 따라 우선순위를 결정하는 변수를 리턴하는 함수
    switch (symbol) {                               //매개변수로 받는 sysbol에 따라
        case '(':                   //왼쪽 괄호를 입력받았을 경우
            return lparen;       //변수 lparen 리턴
   
        case ')':                   //오른쪽 괄호를 입력받았을 경우
            return rparen;      //변수 rparen 리턴
    
        case '+':                 //더하기를 입력받았을 경우
            return plus;        //변수 plus 리턴
    
        case '-':                 //빼기를 입력받았을 경우
            return minus;     //변수 minus 리턴
    
        case '/':                 //나누기를 입력받았을 경우
            return divide;      //변수 divide 리턴
    
        case '*':                 //곱하기를 입력받았을 경우
            return times;       //변수 time 리턴
    
        default:                //그 외의 것을 입력받았을 경우
            return operand;         //변수 operand 리턴
    }
}


precedence getPriority(char x) {            //우선순위를 알 수 있는 함수
    return getToken(x);                 //x를 매개변수로 하여 getToken를 실행한 결과를 리턴
}


void charCat(char* c) {                         //문자 하나를 전달받아 postfixExp에 추가하는 함수
    if (postfixExp == '\0')                  //postfixExp가 NULL값일 경우             
        strncpy_s(postfixExp, c, 1, 1);              //c에 있던 문자를 postfixExp로 복사

    else                                        //postfixExp가 NULL값이 아닐 경우  
        strncat_s(postfixExp, c, 1, 1);              //c에 있던 문자열을 postfixExp 뒤쪽에 이어붙임
}


/**
 * infixExp의 문자를 하나씩 읽어가면서 stack을 이용하여 postfix로 변경한다.
 * 변경된 postfix는 postFixExp에 저장된다.
 */
void toPostfix() {                  //postfix로 변경하는 함수
    char* exp = infixExp;               //infixExp의 문자를 하나씩 읽기 위한 포인터 선언
    char x;                                 //문자 하나를 임시로 저장하기 위한 변수 x 선언

                                             // exp를 증가시켜가면서, 문자를 읽고 postfix로 변경

    while (*exp != '\0') {                      //*exp의 값이 NULL값이 아니면 반복
        if (getPriority(*exp) == operand) {                 
            //*exp를 매개변수로 하는 getPriority를 시행한 값과 operand의 값이 같으면
            x = *exp;                   //x에 *exp의 값 대입
            charCat(&x);            //x의 주소를 매개변수로 하여 charCat 함수 실행
        }

        else if (getPriority(*exp) == lparen) { 
            //*exp를 매개변수로 하는 getPriority를 시행한 값과 lparen의 값이 같으면
            postfixPush(*exp);      //*exp를 매개변수로 하영 postfixPush 함수 실행
        }

        else if (getPriority(*exp) == rparen) {
            //*exp를 매개변수로 하는 getPriority를 시행한 값과 rparen의 값이 같으면
            while ((x = postfixPop()) != '(') {             
                //x에 postfixpop함수 실행 결과를 대입하고, 이 값이 왼쪽 괄호와 같으면 반복
                charCat(&x);            //x의 주소를 매개변수로 하는 charCat 함수 실행
            }
        }

        else {                  //그 외의 경우에
            while (getPriority(postfixStack[postfixStackTop]) >= getPriority(*exp)) {
                //postfixStack[postfixStackTop]을 매개변수로 하는 getpriority 함수를 실행한 결과가
                //*exp를 매개변수로 하여 getPriority를 실행한 결과보다 더 크면
                x = postfixPop();           //x의 값에 postfixPop의 값 대입
                charCat(&x);              //x의 주소를 매개변수로 하는 charCat 함수 실행
            }

            postfixPush(*exp);              //*exp를 매개변수로 하여 postfixPush 함수 실행
        }

        exp++;      //exp의 값 1만큼 증가
     }


    while (postfixStackTop != -1) {
        x = postfixPop();
        charCat(&x);
    }

}


void debug() {                  //디버깅을 실행하는 함수
    printf("\n---DEBUG\n");             //해당 문구 출력
    printf("infixExp = %s\n", infixExp);            //infixExp의 값 출력
    printf("postExp = %s\n", postfixExp);         //postfixExp의 값 출력
    printf("eval result = %d\n", evalResult);       //evalResult의 값 출력
    printf("postfixStack : ");              //해당 문구 출력

    for (int i = 0; i < MAX_STACK_SIZE; i++)        //postfixStack 출력
        printf("%c ", postfixStack[i]);
    printf("\n");
}


void reset() {                      //reset하는 함수
    infixExp[0] = '\0';                 //infixExp[0]을 NULL값으로 초기화
    postfixExp[0] = '\0';               //postfixExp[0]을 NULL 값으로 초기화

    for (int i = 0; i < MAX_STACK_SIZE; i++)        //postfixStack의 요소들을 모두 NULL값으로 초기화
        postfixStack[i] = '\0';            

    postfixStackTop = -1;               //postfixStackTop의 값을 -1로 초기화 (postfixStack이 비어있음을 의미하도록)
    evalStackTop = -1;                  //evalStackTop의 값을 -1로 초기화 (evalStackTop이 비어있음을 의미하도록)
    evalResult = 0;                       //evalResult를 0으로 초기화  ]

    return 0;
}


void evaluation() {
    int opr1;           //정수형 변수 선언
    int opr2;
    int i;

    int length = strlen(postfixExp);            //정수형 변수 length에 postfixExp의 길이를 대입
    char symbol;                                //char 형의 변수 symbol 선언

    evalStackTop = -1;              //evalStackTop의 값을 -1로 초기화

    for (i = 0; i < length; i++) {
        symbol = postfixExp[i];             //symbol에 postfixExp[i]의 값을 대입

        if (getToken(symbol) == operand) {     
            //만약 getToken(symbol)의 값이 operand와 같을 경우
            evalPush(symbol - '0');         //symbol-'0'을 매개변수로 하는 evalPush 함수 실행
        }

        else {                          //그 외의 경우
            opr2 = evalPop();           //opr2에 evalPop함수를 실행한 결과를 대입
            opr1 = evalPop();           //opr1에 evalPop함수를 실행한 결과를 대입

            switch (getToken(symbol)) {
            //sysbol을 매개변수로 getToken을 실행한 결과값에 따라
                case plus:              //plus일 경우
                    evalPush(opr1 + opr2);      //opr1+opr2를 매개변수로 하는 evalPush함수를 실행
                    break;                  //break

                case minus:             //minus일 경우
                    evalPush(opr1 - opr2);      //opr1-opr2를 매개변수로 하는 evalPush함수를 실행
                    break;                  //break
       
                case times:             //times일 경우
                    evalPush(opr1 * opr2);      //opr1 * opr2를 매개변수로 하는 evalPush함수를 실행
                    break;                  //break

                case divide:            //divide일 경우
                    evalPush(opr1 / opr2);      //opr1 / opr2를 매개변수로 하는 evalPush함수를 실행
                    break;                  //break

                default:                    //그 외의 경우
                    break;                  //break
            }
        }
    }

    evalResult = evalPop();             //evalResult의 값에 evalPop 함수의 실행 결과 대입
}