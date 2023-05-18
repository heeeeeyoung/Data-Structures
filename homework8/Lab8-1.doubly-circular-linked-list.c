#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    //struct Node 선언
	int key;                //노드에 저장되는 값인 key
	struct Node* llink;     //노드의 왼쪽 링크 값 Node* llink
	struct Node* rlink;     //노드의 오른쪽 링크 값 Node* rlink
} listNode;


//사용하는 함수 목록
int initialize(listNode** h);
int freeList(listNode* h);
int insertLast(listNode* h, int key);
int deleteLast(listNode* h);
int insertFirst(listNode* h, int key);
int deleteFirst(listNode* h);
int invertList(listNode* h);
int insertNode(listNode* h, int key);
int deleteNode(listNode* h, int key);

void printList(listNode* h);


int main()
{
	char command;               //char 형의 변수 command 선언
	int key;                    //int 형의 변수 key 선언
	listNode* headnode=NULL;

	do{
        //옵션 출력

		printf("----------------------------------------------------------------\n");
		printf("                  Doubly Circular Linked List                   \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize    = z           Print         = p \n");
		printf(" Insert Node   = i           Delete Node   = d \n");
		printf(" Insert Last   = n           Delete Last   = e\n");
		printf(" Insert First  = f           Delete First  = t\n");
		printf(" Invert List   = r           Quit          = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'z': case 'Z':
			initialize(&headnode);      //headnode를 변경할 수 있기때문에 함수 initialize에 headnode의 주소를 넘김
			break;
		case 'p': case 'P':
			printList(headnode);
			break;
		case 'i': case 'I':
			printf("Your Key = ");
			scanf("%d", &key);
			insertNode(headnode, key);
			break;
		case 'd': case 'D':
			printf("Your Key = ");
			scanf("%d", &key);
			deleteNode(headnode, key);
			break;
		case 'n': case 'N':
			printf("Your Key = ");
			scanf("%d", &key);
			insertLast(headnode, key);
			break;
		case 'e': case 'E':
			deleteLast(headnode);
			break;
		case 'f': case 'F':
			printf("Your Key = ");
			scanf("%d", &key);
			insertFirst(headnode, key);
			break;
		case 't': case 'T':
			deleteFirst(headnode);
			break;
		case 'r': case 'R':
			invertList(headnode);
			break;
		case 'q': case 'Q':
			freeList(headnode);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');
    //comman의 값에 q나 Q가 입력될 때 까지 반복

	return 1;
}


int initialize(listNode** h) {
    //초기화하는 함수
	
	if(*h != NULL)          //이미 할당받은 메모리가 있을 경우
		freeList(*h);       //메모리 할당 해제

	
	*h = (listNode*)malloc(sizeof(listNode));       //head 노드에 메모리 할당
	(*h)->rlink = *h;               //노드의 rlink가 자기 자신을 가르키도록
	(*h)->llink = *h;               //노드의 llink가 자기 자신을 가르키도록
	(*h)->key = -9999;              //노드에 저장된 값을 -9999로 설정

	return 1;   
}



int freeList(listNode* h){

	return 0;
}



void printList(listNode* h) {
	int i = 0;
	listNode* p;

	printf("\n---PRINT\n");

	if(h == NULL) {
		printf("Nothing to print....\n");
		return;
	}

	p = h->rlink;

	while(p != NULL && p != h) {
		printf("[ [%d]=%d ] ", i, p->key);
		p = p->rlink;
		i++;
	}
	printf("  items = %d\n", i);


	/* print addresses */
	printf("\n---checking addresses of links\n");
	printf("-------------------------------\n");
	printf("head node: [llink]=%p, [head]=%p, [rlink]=%p\n", h->llink, h, h->rlink);

	i = 0;
	p = h->rlink;
	while(p != NULL && p != h) {
		printf("[ [%d]=%d ] [llink]=%p, [node]=%p, [rlink]=%p\n", i, p->key, p->llink, p, p->rlink);
		p = p->rlink;
		i++;
	}

}



int insertLast(listNode* h, int key) {

	return 1;
}



int deleteLast(listNode* h) {


	return 1;
}



int insertFirst(listNode* h, int key) {


	return 1;
}



int deleteFirst(listNode* h) {


	return 1;

}



int invertList(listNode* h) {


	return 0;
}



int insertNode(listNode* h, int key) {

	return 0;
}



int deleteNode(listNode* h, int key) {

	return 0;
}

