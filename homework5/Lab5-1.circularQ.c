#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 4			//큐 사이즈를 4로 정의

typedef char element;					//char 형의 자료형 element 재정의
typedef struct {								//구조체 QueueType 선언
	element queue[MAX_QUEUE_SIZE];			//char 형의 배열 선언 (크기는 4)
	int front;												//정수형 변수 front 선언
	int rear;												//정수형 변수 rear 선언
}QueueType;
			

//사용될 변수와 함수 정의
QueueType* createQueue();			

int freeQueue(QueueType* cQ);
int isEmpty(QueueType* cQ);
int isFull(QueueType* cQ);
void enQueue(QueueType* cQ, element item);
void deQueue(QueueType* cQ, element* item);
void printQ(QueueType* cQ);
void debugQ(QueueType* cQ);
element getElement();


int main(void) {
	QueueType* cQ = createQueue();				//구조체 포인터변수 cQ에 createQueue를 시행하여 대입
	element data;										//element형의 변수 data 선언

	char command;										//char 형의 command 선언

	do {													//command가 q와 Q가 아닐 경우에 반복
        printf("--------[2021024037]-----------[Kimheeyoung]------------\n");       //나의 학번과 이름 출력
		printf("                     Circular Q                   \n");
        printf("--------[2021024037]-----------[Kimheeyoung]------------\n");       //나의 학번과 이름 출력
		printf(" Insert=i,  Delete=d,   PrintQ=p,   Debug=b,   Quit=q \n");				//옵션 제시
        printf("--------[2021024037]-----------[Kimheeyoung]------------\n");       //나의 학번과 이름 출력

		printf("Command = ");			//사용자로부터 옵션을 입력받음
		scanf_s(" %c", &command);


		switch (command) {				//입력받은 command의 값에 따라 시행
			case 'i': case 'I':						//i또는 I를 입력받았을 경우
				data = getElement();			//getElement함수 실행후 data에 대입
				enQueue(cQ, data);			//매개변수로 cQ와 data를 넘겨 enQueue함수 실행
				break;								//break

			case 'd': case 'D':				//d또는 D를 입력받았을 경우
				deQueue(cQ, &data);		//deQueue함수 실행
				break;							//break
		
			case 'p': case 'P':				//p또는 P를 입력받았을 경우
				printQ(cQ);					//매개변수로 cQ를 넘겨 PrintQ함수 실행
				break;							//break
	
			case 'b': case 'B':				//b또는 B를 입력받았을 경우
				debugQ(cQ);				//매개변수로 cQ를 넘겨 debugQ함수 실행
				break;							//break
		
			case 'q': case 'Q':				//q또는 Q를 입력받았을 경우
				break;							//break
		
			default:							//그 외의 값을 입력받았을 경우
				printf("\n       >>>>>   Concentration!!   <<<<<     \n");			//해당 메세지 출력
				break;							//break
		}	

	} while (command != 'q' && command != 'Q');			//command로 q나 Q가 입력되는 경우 do while문 종료

	return 1;		
}

QueueType* createQueue() {				
	QueueType* cQ;						//QueueType 구조체의 포인터변수 cQ 선언
	cQ = (QueueType*)malloc(sizeof(QueueType));			//cQ에 동적할당

	cQ->front = 0;						//cQ의 front(큐의 head 부분)를 0으로 초기화
	cQ->rear = 0;						//cQ의 rear(큐의 tail 부분)을 0으로 초기화'

	return cQ;			//구조체 포인터변수 cQ 리턴
}


int freeQueue(QueueType* cQ) {				//동적으로 할당받은 cQ를 해제해줌
	if (cQ == NULL)			//cQ가 비어있다면 1을 리턴
		return 1;				
	
	free(cQ);				//cQ가 비어있지 않다면 동적으로 할당받은 cQ를 해제
	return 1;				//그리고 1리턴
}


element getElement()	{				//사용자로부터 큐에 넣을 요소를 입력받는 함수
	element item;						//element형의 변수 item 선언

	printf("Input element = ");		//사용자로부터 큐에 넣을 요소를 입력받음
	scanf_s(" %c", &item);

	return item;							//입력받은 요소를 리턴
}


int isEmpty(QueueType* cQ) {			//큐가 비었는지 확인하는 함수		
	if (cQ->front == cQ->rear) {		//만약 cQ의 front값과 rear값이 같다면
		printf("Circular Queue is empty!");			//큐가 비었음을 알리는 메세지 출력 후 종료
		return 1;
	}

	else										//큐가 비지 않았을 경우
		return 0;
}


int isFull(QueueType* cQ) {				//큐가 가득 찼는지 확인하는 함수
	if (((cQ->rear + 1) % MAX_QUEUE_SIZE) == cQ->front) {		//만약 cQ의 rear+1의 값과 front의 값이 같다면
		printf(" Circular Queue is full!");			//큐가 가득 찼음을 알리는 메세지 출력 후 종료
		return 1;
	}

	else										//큐가 가득 차지 않았을 경우
		return 0;
}

void enQueue(QueueType* cQ, element item) {		//사용자로부터 입력받은 요소를 큐에 넣는 함수
	if (isFull(cQ))			//만약 큐가 가득 차있다면 (isFull 함수 이용)
		return;				//종료

	else {						//큐가 가득 차있지 않다면
		cQ->rear = (cQ->rear + 1) % MAX_QUEUE_SIZE;		//cQ의 rear을 1증가시킴
		cQ->queue[cQ->rear] = item;								//item 을 큐의 rear의 위치에 대입
	}
}


void deQueue(QueueType* cQ, element* item) {			//큐의 앞 원소를 삭제하는 함수
	if (isEmpty(cQ))					//만약 큐가 비어있다면 (isEmpty 함수 이용)
		return;						//종료

	else {								//만약 큐가 비어있지 않다면
		cQ->front = (cQ->front + 1) % MAX_QUEUE_SIZE;		//cQ의 front를 1 증가시킴
		*item = cQ->queue[cQ->front];								//cQ의 front에 해당하는 큐의 원소를 item으로
		return;	
	}
}


void printQ(QueueType* cQ) {				//큐를 출력하는 함수
	int i;						//정수형 변수 i, first, last 선언
	int first;
	int last;

	first = (cQ->front + 1) % MAX_QUEUE_SIZE;			//변수 first에 큐의 fisrt+1 위치 대입
	last = (cQ->rear + 1) % MAX_QUEUE_SIZE;				//변수 rear에 큐의 rear+1위치 대입

	printf("Circular Queue : [");					//큐 출력

	i = first;				//변수 i에 first의 값 대입
	while (i != last) {			//i와 last가 같지 않을 경우 반복
		printf("%3c", cQ->queue[i]);			//큐의 요소들을 출력
		i = (i + 1) % MAX_QUEUE_SIZE;				//i의 값 1만큼 증가
     }

	printf(" ]\n");		//큐 출력 끝
}


void debugQ(QueueType* cQ) {			//큐를 디버깅 하는 함수
	printf("\n---DEBUG\n");		//해당 메세지 출력
	for (int i = 0; i < MAX_QUEUE_SIZE; i++) {		
		if (i == cQ->front) {					//i가 cQ의 front와 같을 경우
			printf("  [%d] = front\n", i);		//i의 값 출력
			continue;											//continue
		}
		printf("  [%d] = %c\n", i, cQ->queue[i]);		//i의 값과 cQ의 i번째 요소 출력
	}

	//printQ(cQ);
	printf("front = %d, rear = %d\n", cQ->front, cQ->rear);			//cQ의 front값과 rear값 출력
}

