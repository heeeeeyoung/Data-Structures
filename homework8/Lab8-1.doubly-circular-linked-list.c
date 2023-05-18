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

		printf("Command = ");           //사용자로부터 command 의 값을 입력받음
		scanf(" %c", &command);

		switch(command) {  
        //command의 값에 따라

		case 'z': case 'Z':         //z나 Z를 입력받을 경우
			initialize(&headnode);      
            //headnode를 변경할 수 있기때문에 함수 initialize에 headnode의 주소를 넘김
			break;

		case 'p': case 'P':         //p나 P를 입력받을 경우
			printList(headnode);    //리스트를 출력하는 함수 실행
			break;

		case 'i': case 'I':         //i나 I를 입력받을 경우
			printf("Your Key = ");  //사용자로부터 추가할 노드 값을 입력받음
			scanf("%d", &key);  
			insertNode(headnode, key);  //노드를 추가하는 함수 실행
			break;

		case 'd': case 'D':         //d나 D를 입력받을 경우
			printf("Your Key = ");  //사용자로부터 삭제할 노드 값을 입력받음
			scanf("%d", &key);      
			deleteNode(headnode, key);  //노드를 삭제하는 함수 실행
			break;

		case 'n': case 'N':         //n이나 N을 입력받을 경우
			printf("Your Key = ");  //사용자로부터 추가할 노드 값을 입력받음
			scanf("%d", &key);
			insertLast(headnode, key);  //리스트의 마지막에 노드를 추가하는 함수 실행
			break;

		case 'e': case 'E':         //e나 E를 입력받을 경우
			deleteLast(headnode);   //리스트의 마지막 노드를 삭제하는 함수 실행
			break;

		case 'f': case 'F':         //f나 F를 입력받을 경우
			printf("Your Key = ");  //사용자로부터 추가할 노드 값을 입력받음
			scanf("%d", &key);
			insertFirst(headnode, key); //리스트의 첫번재에 노드를 추가하는 함수 실행
			break;

		case 't': case 'T':         //t나 T를 입력받을 경우
			deleteFirst(headnode);  //리스트의 첫번째 노드를 삭제하는 함수 실행
			break;

		case 'r': case 'R':         //r이나 R을 입력받을 경우
			invertList(headnode);   //리스트 내의 노드를 역순으로 바꾸는 함수 실행
			break;
            
		case 'q': case 'Q':         //q나 Q를 입력받을 경우
			freeList(headnode);     //메모리 할당을 해제하는 함수 실행
			break;

		default:                    //그 외의 경우 
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
    //할당된 메모리를 해제하는 함수

    if(h->rlink == h)   //만약 노드에 h만 있다면
	{
		free(h);        //h의 동작 할당 해제

		return 0;
	}

	listNode* p = h->rlink;     
    //p를 만들고, h의 rlink를 대입
	listNode* pre = NULL;
    //이전 노드를 가르키는 pre를 만들고 NULL로 초기화

	while(p != NULL && p != h) {
        //p가 NULL이 아니고, p가 h가 아니면 계속 반복

		pre = p;        //pre에 p의 값 대입
		p = p->rlink;   //p에 다음 노드를 가르키는 rlink대입
		
        free(pre);      //pre의 메모리 할당 해제
	}

	free(h);            //h의 메모리 할당 해제

	return 0;
}



void printList(listNode* h) {
    //리스트를 출력하는 함수

	int i = 0;                          //int 형 변수 i선언
	listNode* p;                        //listNode p선언

	printf("\n---PRINT\n"); 

	if(h == NULL) {             //만약 리스트가 비어있다면
		printf("Nothing to print....\n");          //해당 문구 출력
		return;
	}

	p = h->rlink;               //p애 head노드 rlink의 값 대입

	while(p != NULL && p != h) {        //p가 NULL 값이 될 때 까지
		printf("[ [%d]=%d ] ", i, p->key);      //node에 저장된 값 출력
		p = p->rlink;                           //p에 다음 노드를 가르키는 주소를 대입
		i++;                                    //i++ 을 통해 노드를 한칸씩 옮겨감
	}
	printf("  items = %d\n", i);                //입력된 노드의 개수 출력


    //주소 출력
	printf("\n---checking addresses of links\n");
	printf("-------------------------------\n");
	printf("head node: [llink]=%p, [head]=%p, [rlink]=%p\n", h->llink, h, h->rlink);
    //llink의 주소, head의 주소, rlink의 주소 출력

	i = 0;          //변수 i에 0대입
	p = h->rlink;   //p에 head의 rlink 값 대입

	while(p != NULL && p != h) {
        //p가 NULL값이고, p가 h가 아닐때까지 반복

		printf("[ [%d]=%d ] [llink]=%p, [node]=%p, [rlink]=%p\n", i, p->key, p->llink, p, p->rlink);
        //리스트의 처음부터 노드 번호, 저장된 값, llink의 값, p값, rlink의 값 출력

		p = p->rlink;       //p의 값을 다음 노드를 가르키는 곳의 값으로 설정
		i++;            //i++를 통해 다음 노드로 이동
	}

}



int insertLast(listNode* h, int key) {
    //리스트의 마지막에 노드 삽입

	if (h == NULL) 
        return -1;
    //노드가 비어있을 경우    

	listNode* node = (listNode*)malloc(sizeof(listNode));
	//새로 추가하는 노드인 node를 만들고 메모리 할당

    node->key = key;        
    //node의 key 에 사용자가 추가하기 위해 입력한 값 대입
	
    node->rlink = NULL;     //node의 rlink를 NULL로 초기화
	node->llink = NULL;     //node의 llink를 NULL로 초기화

	if (h->rlink == h)      //리스트에 있는 노드가 하나라면
	{
		h->rlink = node;    //h의 rlink에 node 대입
		h->llink = node;    //h의 llink에 node 대입
		node->rlink = h;    //node의 rlink에 h대입
		node->llink = h;    //node의 llink에 h대입
	} 
    
    else {
        //리스트에 있는 노드가 하나가 아니라면

		h->llink->rlink = node;     //h의 llink의 rlink에 node 대입
		node->llink = h->llink;     //node의 llink에 h의 llink 대입
		h->llink = node;            //h의 llink에 node 대입
		node->rlink = h;            //node의 rlink에 h대입
        //리스트의 마지막에 노드를 추가하고, 전체 노드들의 연결 조정
	}

	return 0;
}



int deleteLast(listNode* h) {
    //리스트의 마지막 노드 삭제

    if (h->llink == h || h == NULL)
	{   //만약 h의 link가 h이거나, h가 NULL 일경우
        //리스트가 비어있을 경우

		printf("nothing to delete.\n");     //삭제할 리스트가 없음

		return 0;
	}

	listNode* nodetoremove = h->llink;
    //nodetoremove에 h의 llink 대입


	nodetoremove->llink->rlink = h;
    //nodetoremove의 llink의 rlink에 h대입
	h->llink = nodetoremove->llink;
    //h의 llink에 nodetoremove의 llink 대입
    //리스트의 마지막 노드를 삭제하고, 남은 노드들의 연결 조정

	free(nodetoremove);     //nodetoremove의 메모리 할당 해제

	return 0;
}



int insertFirst(listNode* h, int key) {
    //리스트의 첫번째에 노드 추가

    listNode* node = (listNode*)malloc(sizeof(listNode));
    //추가할 노드인 node 에 메모리 할당
    
	node->key = key;        
    //node의 key에 사용자가 추가하고자 한 값인 key 대입
	node->rlink = NULL;     //node의 rlink를 NULL로 초기화
	node->llink = NULL;     //node의 llink를 NULL로 초기화


	node->rlink = h->rlink;     //node의 rlink에 h의 rlink대입
	h->rlink->llink = node;     //h의 rlink의 llink에 node 대입
	node->llink = h;            //node의 llink에 h 대입
	h->rlink = node;            //h의 rlink에 node 대입
    //리스트의 첫번째에 노드를 추가하고, 전체 노드들의 연결 조정


	return 0;
}



int deleteFirst(listNode* h) {
    //리스트의 첫번째 노드를 삭제하는 함수

    if (h == NULL || h->rlink == h)
	{   //만약 리스트가 비어있다면

		printf("nothing to delete.\n");
		return 0;
	}

	listNode* nodetoremove = h->rlink;
    //nodetoremove에 h의 rlink 대입


	nodetoremove->rlink->llink = h;
    //nodetoremove의 rlink의 llink에 h대입
	h->rlink = nodetoremove->rlink;
    //h의 rlink에 nodetoremove의 rlink대입
    //첫번째 노드를 삭제하고, 남은 노드들의 연결 조정

	free(nodetoremove);     //nodetoremove의 메모리 할당 해제

	return 0;
}



int invertList(listNode* h) {
    //리스트들의 노드들을 역순으로 바꿈

    if(h->rlink == h || h == NULL) {   
        //만약 h의 rlink가 h와 같거나, h가 NULL이라면
        //만약 리스트가 비어있다면

		printf("nothing to invert...\n");
		return 0;
	}

	listNode *n = h->rlink;
    //n에 h의 rlink 대입
	listNode *trail = h;
    //trail에 h대입
	listNode *middle = h;
    //middle에 h 대입

	h->llink = h->rlink;   
    //전 노드를 가르키는 llink에 다음 노드를 가르키는 rlink대입

	while(n != NULL && n != h){
        //n이 NULL이 아니거나, h가 아니면 반복

		trail = middle;     //trail에 middle 대입
		middle = n;         //middle에 n 대입
		n = n->rlink;       //n에 n의 rlink 대입
		middle->rlink = trail;  //middle의 rlink에 trail 대입
		middle->llink = n;      //middle의 llink에 n 대입

        //리스트의 노드들을 역순으로 재배치하는 과정을 끝까지 반복
	}

	h->rlink = middle;      //h의 rlink에 middle 값 대입

    return 0;
}



int insertNode(listNode* h, int key) {
    //리스트에 노드를 추가하는 함수

    listNode* node = (listNode*)malloc(sizeof(listNode));       
    //listNode 구조체 변수 node를 선언후, 메모리 동적 할당

	node->key=key;                                           
    //node의 key에 사용자로부터 입력받은 추가하고자 하는 값을 대입

	if (h == NULL)             //만약 리스트가 비어있다면
	{
		node->llink=node;   //추가하는 노드의 llink가 자기 자신을 가르키도록
        node->rlink=node;   //추가하는 노드의 rlink가 자기 자신을 가르키도록
        h=node;             //h노드를 새로 추가하는 노드로 설정
	}

    //리스트가 비어있지 않을 경우, 노드를 삽입할 위치를 찾음
	listNode* n = h;        //h노드를 listNode n에 대입

	while(n != NULL) {   
        //n이 NULL값이 아니면 반복

		while(n->rlink != h && n->rlink->key<key) {     
            //현재 노드의 rlink의 값이 h와 다르거나, 
            //현재 노드의 rlink로 이어지는 저장된 값이 추가한 값보다 작으면 반복               
			
            n=n->rlink;
		}
	}

    //추가한 노드를 다른 노드들과 연결
    node->rlink=n->rlink;   //node의 rlink를 현재 노드의 rlink로 설정
    node->llink=n;          //node의 llink를 현재 노드로 설정
    node->rlink->llink=node;    //node의 rlink로 이어지는 llink를 node로 설정
    n->rlink=node;          //현재 노드의 rlink를 node로 설정

	return 0;
}



int deleteNode(listNode* h, int key) {
    //사용자가 입력한 값의 노드를 삭제

    if (h==NULL){
        printf("Nothing to delete...");

        return 0;
    }

    listNode *n=h;
    //현재 노드를 가르킬 노드를 생성하고, h의 값 대입
    listNode*pre=NULL;
    //이전 노드를 가르킬 노드를 생성하고, NULL 값으로 초기화

    while(n->key !=key){
        //현재 노드의 key값과 사용자가 입력한 값이 다르면 반복

        if(n->rlink==h){
            //각 노드들을 탐색하는 현재 노드 n이 마지막까지 도달하면
            //노드가 없음을 출력

            printf("Cannot find the node for key ...");
        }

        pre=n;      //이전 노드를 가르키는 노드에 현재 노드 대입
        n=n->rlink; //현재 노드에 다음 노드로 연결하는 rlink 대입
    }

    //삭제할 노드를 찾아서 삭제 진행

    if (n==h && n->rlink==h){
        //리스트에 노드가 하나만 있는 경우, 첫번째 노드 삭제

        h=NULL;     //리스트가 비게 되기 때문에 h를 NULL로 초기화
    }

    if(n==h){
        //첫번째 노드 삭제
        
        pre=h->llink;   
        //이전 노드를 가르키는 pre에 h의 llink값 대입 
        h=h->rlink;
        //h에 h의 rlink 대입
        pre->rlink=h;
        //이전 노드를 가르키는 pre의 rlink에 h대입
        h->llink=pre;
        //h의 llink에 이전 노드를 가르키는 pre 대입
    }

    if (n->rlink==h){
        //마지막 노드 삭제

        pre->rlink=h;      
        //이전 노드를 가르키는 pre의 rlink에 h 대입
        h->llink=pre;
        //h의 llink에 pre대입
    }

    else{
        //중간 노드를 삭제하는 경우

        pre->rlink=n->rlink;       
        //이전 노드를 가르키는 pre의 rlink에 현재 노드의 rlink대입
        (n->rlink)->llink=pre;
        //현재 노드의 rlink의 llink에 pre 대입 
    }

    free(n);        //n의 메모리 할당 해제

	return 0;
}

