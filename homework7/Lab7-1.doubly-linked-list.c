#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int key;
	struct Node* llink;         //왼쪽으로 가는 링크
	struct Node* rlink;         //오른쪽으로 가는 링크
} listNode;                     //구조체 선언


typedef struct Head {
	struct Node* first;         //리스트의 첫번째 노드를 가르킴
}headNode;                      //구조체 선언


int initialize(headNode** h);       //이중포인터로 받도록
int freeList(headNode* h);          //싱글포인터로 받음
int insertNode(headNode* h, int key);
int insertLast(headNode* h, int key);
int insertFirst(headNode* h, int key);
int deleteNode(headNode* h, int key);
int deleteLast(headNode* h);
int deleteFirst(headNode* h);
int invertList(headNode* h);

void printList(headNode* h);


int main()
{
	char command;               //char형의 변수 command 선언
	int key;                    //int 형의 변수 key 선언

	headNode* headnode=NULL;    //리스트를 NULL로 초기화


	do{             //반복
		printf("---------[2021024037]-----------[Kimheeyoung]------------------\n");           //옵션 출력
		printf("                     Doubly Linked  List                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize    = z           Print         = p \n");
		printf(" Insert Node   = i           Delete Node   = d \n");
		printf(" Insert Last   = n           Delete Last   = e\n");
		printf(" Insert First  = f           Delete First  = t\n");
		printf(" Invert List   = r           Quit          = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");                       //사용자로부터 command 값을 입력받음
		scanf(" %c", &command);

		switch(command) {               //입력받은 command 값에 따라 실행

		case 'z': case 'Z':             //z나 Z를 입력받았을 경우
			initialize(&headnode);      //headnode의 주소를 매개변수로 하는 initialize 함수 실행 
			break;                      //break

		case 'p': case 'P':             //p나 P를 입력받았을 경우
			printList(headnode);        //headnode를 매개변수로 하는 printList 함수 실행    
			break;                      //break

		case 'i': case 'I':             //i나 I를 입력받았을 경우
			printf("Your Key = ");      //사용자로부터 리스트에 추가 할 노드 값을 입력받음
			scanf("%d", &key);
			insertNode(headnode, key);  //headnode와 key 값을 매개변수로 하는 insertNode 함수 실행
			break;                      //break

		case 'd': case 'D':             //d나 D를 입력받았을 경우
			printf("Your Key = ");      //사용자로부터 리스트에서 삭제 할 노드를 입력받음
			scanf("%d", &key);  
			deleteNode(headnode, key);  //headNode와 key 값을 매개변수로 하는 deleteNode 함수 실행
			break;                      //break

		case 'n': case 'N':             //n이나 N을 입력받았을 경우
			printf("Your Key = ");      //사용자로부터 리스트의 마지막에 넣을 노드 값을 입력받음
			scanf("%d", &key);          
			insertLast(headnode, key);  //hearnode와 key 값을 매개변수로 하는 insertLast 함수 실행
			break;                      //break        

		case 'e': case 'E':             //e나 E를 입력받았을 경우
			deleteLast(headnode);       //headnode를 매개변수로 하는 deleteLast 함수 실행
			break;                      //break

		case 'f': case 'F':             //f나 F를 입력받았을 경우
			printf("Your Key = ");      //사용자로부터 리스트의 첫번째에 추가한 노드 값을 입력받음
			scanf("%d", &key);  
			insertFirst(headnode, key); //headnode와 key 값을 매개변수로 하는 inserFirst 함수 실행
			break;                      //break

		case 't': case 'T':             //t나 T를 입력받았을 경우
			deleteFirst(headnode);      //headnode를 매개변수로 하는 deleteFirst 함수 실행
			break;                      //break

		case 'r': case 'R':             //r이나 R를 입력받을 경우
			invertList(headnode);       //headnode를 매개변수로 하는 inverList 함수 실행
			break;                      //break

		case 'q': case 'Q':             //q나 Q를 입력받았을 경우
			freeList(headnode);         //headnode를 매개변수로 하는 fressList 함수 실행
			break;                      //break

		default:                        //그 외의 경우    
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");          //해당 메세지 출력
			break;                      //break                            
		}

	}while(command != 'q' && command != 'Q');           //command가 q나 Q일 때까지 계속 반복

	return 1;
}


int initialize(headNode** h) {          //리스트를 초기화하는 함수
	if(*h != NULL) {            //만약 리스트가 비어있다면
		freeList(*h);           //*h 의 메모리 할당 해제
    }

	*h = (headNode*)malloc(sizeof(headNode));       //*h에 메모리 동적 할당
	(*h)->first = NULL;                             //리스트를 NULL값으로 초기화    
	return 1;                                       //return 1
}

int freeList(headNode* h){          //할당된 메모리를 해제 하는 함수
	listNode* p = h->first;         //리스트의 처음을 p에 대입

	listNode* prev = NULL;          //리스트의 처음을 NULL 값으로 초기화
	while(p != NULL) {              //만약 p가 NULL이 아니라면
		prev = p;                   
		p = p->rlink;
		free(prev);                 //리스트 안의 모든 노드들의 메모리 할당 해제
	}

	free(h);                        //리스트의 첫 부분도 메모리 할당 해제

	return 0;                       //return 0    
}


void printList(headNode* h) {       //리스트를 출력하는 함수
	int i = 0;                      //int형 변수 i 선언
	listNode* p;                    //구조체 listNode 변수 p 선언

	printf("\n---PRINT\n");         //print

	if(h == NULL) {                 //만약 리스트가 비어있다면
		printf("Nothing to print....\n");       //출력할게 없음을 알리는 메세지 출력
		return;                                 //return
	}

	p = h->first;                   //리스트의 처음을 p에 대입

	while(p != NULL) {              //p가 NULL이 아니라면
		printf("[ [%d]=%d ] ", i, p->key);      //리스트 안의 값들을 순서대로 출력
		p = p->rlink;
		i++;                        //i의 값 하나 증가
	}

	printf("  items = %d\n", i);    //리스트 안의 노드의 개수 출력
}


int insertLast(headNode* h, int key) {          //리스트의 가장 마지막에 노드를 추가하는 함수

	listNode* node = (listNode*)malloc(sizeof(listNode));       //구조체 listNode의 변수 node에 메모리 동적 할당
	node->key = key;               //node의 key에 사용자로부터 입력받은 추가할 노드값을 대입 
	node->rlink = NULL;            //node의 rlink와 
	node->llink = NULL;            //node의 llink를 NULL로 초기화 

	if (h->first == NULL)           //만약 리스트가 비어있을 경우
	{   
		h->first = node;            //node를 리스트의 처음으로
		return 0;                   //return 0
	}

	listNode* n = h->first;         //구조체 listNode의 변수 n에 리스트의 첫번째 대입

	while(n->rlink != NULL) {       //리스트의 오른쪽이 비어있으면
		n = n->rlink;               //n에 리스트의 오른쪽으로 가는 변수 대입
	}

	n->rlink = node;                //node의 값을 오른쪽으로 가는 변수에 대입
	node->llink = n;                //node의 왼쪽으로 가는 변수에 n대입

	return 0;                       //retrn 0
}


int deleteLast(headNode* h) {       //리스트의 마지막 노드를 삭제하는 함수

	if (h->first == NULL)           //만약 리스트가 비어있다면
	{
		printf("nothing to delete.\n");     //삭제할 노드가 없음을 알리는 메세지 출력
		return 0;                           //return 0
	}

	listNode* n = h->first;         //listNode 구조체 변수 n에 리스트의 첫번째 위치 대입
	listNode* trail = NULL;         //listnode 구조페 변수 trail을 선언하고 NULL로 초기화

	if(n->rlink == NULL) {          //만약 리스트가 비어있다면
		h->first = NULL;            //리스트의 첫번째를 NULL로 초기화
		free(n);                    //리스트의 첫번째의 메모리 할당 해제
		return 0;                   //return 0
	}

	while(n->rlink != NULL) {       //리스트가 비어있지 않다면
		trail = n;                  //trail에 n의 값 대입
		n = n->rlink;               //n에 n의 rlink의 값 대입
	}

	trail->rlink = NULL;            //trail의 rlink를 NULL로 초기화
	free(n);                        //n의 메모리 할당 해제

	return 0;                       //return 0
}



int insertFirst(headNode* h, int key) {         //리스트의 맨 앞에 노드를 추가하는 함수
	listNode* node = (listNode*)malloc(sizeof(listNode));       //listNode 구조체 변수 node를 선언하고 동적 할당
	node->key = key;                    //node의 key에 사용자로부터 입력받은 추가할 노드 값 대입
	node->rlink = node->llink = NULL;   //node의 오른쪽으로 가는 변수, 왼쪽으로 가는 변수 모두 NULL로 초기화

	if(h->first == NULL)            //만약 리스트가 비어있다면
	{
		h->first = node;            //리스트의 처음은 node    
		return 1;                   //return 0
	}

	node->rlink = h->first;         //node의 오른쪽으로 가는 변수에 리스트의 처음 값 대입
	node->llink = NULL;             //node의 왼쪽으로 가는 변수는 NULL로 초기화

	listNode *p = h->first;         
	p->llink = node;                //새로 추가한 node를 왼쪽으로 가는 링크에 대입, 
	h->first = node;                //그리고 리스트의 첫번째로 설정

	return 0;                       //return 0
}


int deleteFirst(headNode* h) {          //리스트의 첫번째 노드를 삭제하는 함수

	if (h->first == NULL)               //만약 리스트가 비어있을 경우
	{
		printf("nothing to delete.\n");         //삭제할 노드가 없음을 알리는 메세지 출력
		return 0;                               //return 0
	}

	listNode* n = h->first;                     //listNode 구조체 변수 n에 리스트의 처음 대입      
	h->first = n->rlink;                        //n의 link를 리스트의 처음에 대입       

	free(n);                                    //n의 메모리 할당 해제

	return 0;                                   //return 0
}



int invertList(headNode* h) {           //리스트 안의 노드의 순서를 역순으로 바꿔주는 함수
	if(h->first == NULL) {                      //만약 리스트가 비어있다면
		printf("nothing to invert...\n");           //역순으로 바꿀 노드가 없음을 알리는 메세지 출력
		return 0;                                   //return 0
	}

	listNode *n = h->first;                 //리스트의 처음을 listNode 구조체 변수 n에 대입
	listNode *trail = NULL;                 //구조체 listNode 변수 trail 을 선언후 NULL로 초기화
	listNode *middle = NULL;                //구조체 listNode 변수 middle 을 선언후 NULL로 초기화

	while(n != NULL){                       //n이 NULL이 아닐때까지
		trail = middle;                     //리스트 안의 노드들을 역순으로 바꿈
		middle = n;
		n = n->rlink;
		middle->rlink = trail;
		middle->llink = n;
	}

	h->first = middle;                      //middle 이 리스트의 맨 앞으로 왔기 때문에 h->first에 middle 대입

	return 0;                               //return 0
}



int insertNode(headNode* h, int key) {                  //사용자가 입력한 숫자를 리스트에 추가하는 함수
	listNode* node = (listNode*)malloc(sizeof(listNode));       //listNode 구조체 변수 node를 선언후, 메모리 동적 할당
	node->key = key;                                            //node의 key에 사용자로부터 입력받은 추가하고자 하는 값을 대입
	node->llink = node->rlink = NULL;                           //node의 llink와 rlink를 모두 NULL로 초기화

	if (h->first == NULL)                                       //만약 리스트가 비어있다면
	{
		h->first = node;                                        //node를 리스트의 첫번째로
		return 0;
	}

	listNode* n = h->first;             //listNode 구조체 변수 n을 만들고, 리스트의 처음을 대입

	while(n != NULL) {                              //n이 NULL값이 아니면 반복
		if(n->key >= key) {                         //만약 n의 key가 사용자로부터 입력받은 값보다 크거나 같으면
			if(n == h->first) {             //입력받은 값이 리스트의 첫번째 값과 같다면
				insertFirst(h, key);        //h와 key를 매개변수로 하는 inserFirst 함수 실행
			} 
            
            else {                          //입력받은 값이 리스트의 첫번째 값보다 같지 않다면
				node->rlink = n;            //리스트 내애 입력받은 값의 위치를 찾음
				node->llink = n->llink;
				n->llink->rlink = node;
			}
			return 0;
		}

		n = n->rlink;                       //변경된 값에 맞추어 n의 값 설정
	}
    insertLast(h, key);                 //위의 경우가 아니라면 입력받은 값이 가장 작은 것 이므로, insertLast 함수 실행 

	return 0;
}


int deleteNode(headNode* h, int key) {      //사용자가 입력한 노드를 리스트에서 삭제하는 함수
	if (h->first == NULL)                   //만약 리스트가 비어있다면
	{
		printf("nothing to delete.\n");     //삭제 할 노드가 없음을 알리는 메세지 출력
		return 1;
	}

	listNode* n = h->first;             //listNode 구조체 변수 n선언 후, 리스트의 첫번째를 대입

	while(n != NULL) {                      //n이 NULL일 동안 반복
		if(n->key == key) {                     //만약 n의 key가 사용자가 삭제하기 위해 입력한 값과 같다면
			if(n == h->first) {             //만약 n이 리스트의 첫번째 요소라면
				deleteFirst(h);             //h를 매개변수로 하는 deleteFirst 함수 실행
			} 
            
            else if (n->rlink == NULL){   //rlink가 NULL값이라면
				deleteLast(h);      //h를 매개변수로 하는 deleteLast 함수 실행  
			} 
            
            else {                      //그 외의 상황이라면
				n->llink->rlink = n->rlink;     //n의 llink의 rlink에 n의 rlink를 대입
				n->rlink->llink = n->llink;     //nd의 rlink의 llink에 n의 llink를 대입
				free(n);                        //n의 메모리 할당해제
			}
			return 1;               //return 0
		}

		n = n->rlink;           //n의 값을 n의 rlink 값으로 설정
	}


	printf("cannot find the node for key = %d\n", key);     
    //사용자가 입력한 값이 리스트에 없을 경우, 해당 노드가 없음을 알리는 메세지 출력

	return 1;
}

