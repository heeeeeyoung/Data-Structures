#include<stdio.h>
#include<stdlib.h>


typedef struct Node {	    //구조체형인 Node 선언후
	int key;
	struct Node* link;  
} listNode;                 //구조체변수 listNode 선언


typedef struct Head {       //구조체형인 Head 선언후
	struct Node* first;     
} headNode;                 //구조체변수 headNode 선언



//사용될 변수와 함수 선언
headNode* initialize(headNode* h);
int freeList(headNode* h);
int insertFirst(headNode* h, int key);
int insertNode(headNode* h, int key);
int insertLast(headNode* h, int key);
int deleteFirst(headNode* h);
int deleteNode(headNode* h, int key);
int deleteLast(headNode* h);
int invertList(headNode* h);

void printList(headNode* h);



int main() {
	char command;               //char 형의 변수 command 선언
	int key;                    //정수형의 변수 key 선언
	headNode* headnode=NULL;    //headNode 포인터 변수 headnode를 선언하고 NULL값으로 초기화

	do {               

		printf("------------[2021024037]----------------[Kimheeyoung]--------------\n");        //나의 학번과 이름 출력
		printf("                     Singly Linked List                         \n");           //해당 메세지 출력
		printf("------------[2021024037]----------------[Kimheeyoung]--------------\n");        //나의 학번과 이름 출력
		printf(" Initialize    = z           Print         = p \n");                            //옵션 출력
		printf(" Insert Node   = i           Delete Node   = d \n");
		printf(" Insert Last   = n           Delete Last   = e\n");
		printf(" Insert First  = f           Delete First  = t\n");
		printf(" Invert List   = r           Quit          = q\n");
		printf("------------[2021024037]----------------[Kimheeyoung]--------------\n");         //나의 학번과 이름 출력

		printf("Command = ");           //사용자로부터 command값을 입력받음
		scanf(" %c", &command);

		switch(command) {               //command의 값에 따라 각각의 case 실행
		    case 'z': case 'Z':                     //command의 값이 z나 Z일 경우
			    headnode = initialize(headnode);    //headnode를 매개변수로 하는 initialize함수 실행후, headnode에 대입
			    break;                              //break
		
            case 'p': case 'P':                     //command의 값이 p나 P일 경우
		    	printList(headnode);                //headnode를 매개변수로 하는 함수 printList실행
			    break;                              //break
		
            case 'i': case 'I':                     //command의 값이 i나 I일 경우
		    	printf("Your Key = ");              //사용자로부터 key값을 입력받음
			    scanf("%d", &key);
			    insertNode(headnode, key);          //headnode와 key값을 매개변수로 하는 함수 inserNode 실행
			    break;                              //break
    
            case 'd': case 'D':                     //command의 값이 d나 D일 경우
		    	printf("Your Key = ");              //사용자로부터 key값을 입력받음
		    	scanf("%d", &key);
			    deleteNode(headnode, key);          //headnode와 key값을 매개변수로 하는 함수 deleteNode 실행
			    break;                              //break
    
            case 'n': case 'N':                     //command의 값이 n이나 N일 경우                
			    printf("Your Key = ");              //사용자로부터 key값을 입력받음
			    scanf("%d", &key);
			    insertLast(headnode, key);          //headnode와 key값을 매개변수로 하는 함수 inserLast 실행
			    break;
		
            case 'e': case 'E':                     //command의 값이 e나 E일 경우
			    deleteLast(headnode);               //headnode를 매개변수로 하는 deleteLast 함수 실행
			    break;                              //break
		
            case 'f': case 'F':                     //command의 값이 f나 F일 경우
		    	printf("Your Key = ");              //사용자로부터 key값을 입력받음
			    scanf("%d", &key);
			    insertFirst(headnode, key);         //headnode와 key를 매개변수로 하는 inserFisrt함수 실행
			    break;
		
            case 't': case 'T':                     //command의 값이 t나 T일 경우    
			    deleteFirst(headnode);              //headnode를 매개변수로 하는 함수 deleteFirst 실행
			    break;                              //break
		    
            case 'r': case 'R':                     //command의 값이 r이나 R일 경우
			    invertList(headnode);               //headenode를 매개변수로 하는 invertList 실행
			    break;                              //break
		
            case 'q': case 'Q':                     //command의 값이 q나 Q일 경우
			    freeList(headnode);                 //headnode를 매개변수로 하는 freeList 함수 실행
			    break;                              //break
		
            default:                                //그 외의 경우
			    printf("\n       >>>>>   Concentration!!   <<<<<     \n");      //해당 문구 출력 후
			    break;                                                          //break
		}   

	}while(command != 'q' && command != 'Q');                   //command의 값이 q나 Q가 아닐경우 무한반복

	return 1;
}


headNode* initialize(headNode* h) {                //노드 초기화

	if(h != NULL)                   //만약 headNode가 비어있지 않으면
		freeList(h);                //h를 매개변수로 하는 freeList함수를 실행 

	headNode* temp = (headNode*)malloc(sizeof(headNode));   //headNode에 대한 메모리를 동적할당
	temp->first = NULL;                         //temp의 first라는 필드를 NULL값으로 초기화
	return temp;
}

int freeList(headNode* h){          //동적 할당을 해제해줌
	listNode* p = h->first;         //h의 first를 p에 대입

	listNode* prev = NULL;          //listNode의 포인터 변수 prev 선언 후 NULL 로 초기화

	while(p != NULL) {              //노드가 비어있지 않다면
		prev = p;                   //prev에 p의 값 대입
		p = p->link;                //p에 p의 link의 값을 대입
		free(prev);                 //prev의 동적 할당 해제 (h->first 부분)
	}


	free(h);                        //h의 동적 할당 해제 (매개변수로 받은 headNode* h)

	return 0;
}


int insertNode(headNode* h, int key) {                          //노드에 새로운 값 추가

	listNode* node = (listNode*)malloc(sizeof(listNode));       //node 에 동적할당
	node->key = key;                                            //node의 key에 매개변수로 받은 key 값 대입
	node->link = NULL;                                          //node의 link 값을 NULL 값으로 초기화

	if (h->first == NULL)                                       //만약 노드가 비어있다면
	{
		h->first = node;                                        //h의 first값에 node값을 대입
		return 0;
	}

	listNode* n = h->first;                                     //노드가 비어있지 않다면 listNode 포인터 변수 n에 h의 first의 값 대입
	listNode* trail = h->first;                                 //listNode 포인터 변수 trail에 h의 first갑 대입

	while(n != NULL) {                                          //n이 NULL값이 될 때 까지
		if(n->key >= key) {                                     //만약 n의 key가 매개변수로 전달받은 key보다 크거나 같다면
			if(n == h->first) {                                 //만약 n이 매개변수로 받은 h의 first와 같다면
				h->first = node;                                //h의 first에 node 값 대입
				node->link = n;                                 //node의 linke에 n의 값 대입
			} 
            
            else {                                              //n이 매개변수로 받은 h의 first와 같지 않다면                                       
				node->link = n;                                 //node의 link에 n의 값 대입
				trail->link = node;                             //trail의 link에 node의 값 대입
			}
			return 0;
		}

		trail = n;                                  //trail에 n의 값 대입
		n = n->link;                                //n에 n의 link의 값 대입
	}

	trail->link = node;                             //trail의 link에 node의 값 대입
	return 0;
}


int insertLast(headNode* h, int key) {                              //노드의 마지막에 새로운 값 추가

	listNode* node = (listNode*)malloc(sizeof(listNode));               //node의 동적 할당
	node->key = key;                                                    //node의 key에 매개변수로 전달받은 key의 값 대입
	node->link = NULL;                                                  //node의 link를 NULL로 초기화

	if (h->first == NULL)                     //만약 노드가 비어있으면
	{
		h->first = node;                        //h의 first에 node 대입
		return 0;
	}

	listNode* n = h->first;                     //n에 h의 first값 대입    

	while(n->link != NULL) {                    //n의 link가 NULL이 아니면 계속 반복
		n = n->link;                            //n에 n의 link대입
	}
	n->link = node;                             //n의 link에 node 대입
    
	return 0;
}


int insertFirst(headNode* h, int key) {                         //노드의 처음에 새로운 값 추가

	listNode* node = (listNode*)malloc(sizeof(listNode));       //node에 동적할당
	node->key = key;                                            //node의 key에 매개변수로 받은 key 값 대입

	node->link = h->first;                                      //node의 링크를 head의 first의 값으로 바꾸고
	h->first = node;                                            //hear의 first를 node로 만듦

	return 0;
}


int deleteNode(headNode* h, int key) {                          //노드 삭제

	if (h->first == NULL)                                       //만약 노드가 비어있다면
	{
		printf("nothing to delete.\n");                         //노드가 비어있음을 알리는 메세지 출력
		return 0;
	}
                                                                //노드가 비어있지 않으면                    
	listNode* n = h->first;                                     //h의 first를 n에 대입
	listNode* trail = NULL;                                     //trail 선언 후 NULL로 초기화    

	while(n != NULL) {                      //n이 NULL값이 아니면 계속 반복
		if(n->key == key) {                 //n의 key와 매개변수로 받은 key의 값이 같으면
			if(n == h->first) {                 //만약 n이 h의 first와 같으면
				h->first = n->link;             //h의 first에 n의 link 값 대입
			} else {                            //그렇지 않으면
				trail->link = n->link;          //trail의 link에 n의 link값 대입
			}
			free(n);                            //n의 동적 할당 해제
			return 0;
		}

		trail = n;                      //trail에 n의 값 대입
		n = n->link;                    //n에 n의 link 값 대입    
	}

	printf("cannot find the node for key = %d\n", key);         //지우고자 하는 값을 찾을 수 없음을 알리는 메세지 출력
	return 0;

}



int deleteLast(headNode* h) {                       //노드의 마지막에 있는 값 삭제

	if (h->first == NULL)                           //만약 노드가 비어있는 경우
	{
		printf("nothing to delete.\n");             //비어있음을 알리는 메세지 출력
		return 0;
	}

	listNode* n = h->first;                         //n에 h의 first값 대입ㄹ
	listNode* trail = NULL;                         //trail 선언 후 초기화

	if(n->link == NULL) {                           //만약 노드의 끝이면
		h->first = NULL;                            //h의 first를 NULL로 초기화
		free(n);                                    //n의 동적할당 해제
		return 0;
	}

	while(n->link != NULL) {                        //n의 link가 NULL이 아니면 계속 반복
		trail = n;                                  //trail에 n의 값 대입
		n = n->link;                                //n에 n의 link 값 대입
	}

	trail->link = NULL;                             //trail의 link의 값을 NULL로 초기화시켜주고
	free(n);                                        //n의 동적 할당 해제

	return 0;
}



int deleteFirst(headNode* h) {                      //노드의 첫번째에 있는 값 삭제

	if (h->first == NULL)                           //만약 노드가 비어있다면
	{
		printf("nothing to delete.\n");             //노드가 비어있음을 알리는 메세지 출력
		return 0;                   
	}

	listNode* n = h->first;                         //listNode의 포인터 변수 n에 h의 first값 대입        

	h->first = n->link;                             //h의 first에 n의 link의 값 대입
	free(n);                                        //n의 동적할당 해제

	return 0;
}



int invertList(headNode* h) {                           //노드를 역순으로 바꾸는것


	if(h->first == NULL) {                              //만약 노드가 비어있다면
		printf("nothing to invert...\n");               //노드가 비어있음을 알리는 메세지 출력
		return 0;
	}

	listNode *n = h->first;                             //n에 h의 first대입
	listNode *trail = NULL;                             //trail변수를 초기화하여 선언
	listNode *middle = NULL;                            //middle 변수를 초기화하여 선언

	while(n != NULL){                                   //n이 NULL값이 될 때까지 반복
		trail = middle;                                 //trail에 middle값 대입
		middle = n;                                     //middle에 n의 값 대입
		n = n->link;                                    //n에 n의 link의 값 대입
		middle->link = trail;                           //middle의 link에 trail의 값 대입
	}

	h->first = middle;                                  //h의 first를 middle의 위치로 

	return 0;
}



void printList(headNode* h) {                    //노드를 출력해주는 함수
	int i = 0;
	listNode* p;    

	printf("\n---PRINT\n");                         //해당 문구 출력

	if(h == NULL) {                                 //만약 노드가 비어있다면
		printf("Nothing to print....\n");           //노드가 비어있음을 알리는 메세지 출력
		return;
	}

	p = h->first;                                   //h의 first를 이용하여, h의 firt값을 p에 대입

	while(p != NULL) {                              //p가 NULL값이 될 때까지 반복        
		printf("[ [%d]=%d ] ", i, p->key);          //노드 번호와 해당 값을 출력
		p = p->link;                                //p를 이용하여 다음 노드로 이동
		i++;                                        //변수 i를 1만큼 증가
	}

	printf("  items = %d\n", i);                    //노드의 개수를 출력
}
