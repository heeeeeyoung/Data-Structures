#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    //node 구조체 생성
	int key;
	struct node *left;
	struct node *right;
} Node; 


//스택 설정
#define MAX_STACK_SIZE		20      //최대 사이즈를 20으로 설정
Node* stack[MAX_STACK_SIZE];        //Node* 를 이용하여 사이즈가 20인 stack 생성
int top = -1;                       //스택을 비움

Node* pop();        //스택에서 값을 빼는 pop  
void push(Node* aNode);     //스택에 값을 추가하는 push


//큐 설정
#define MAX_QUEUE_SIZE		20      //최대 사이즈를 20으로 설정
Node* queue[MAX_QUEUE_SIZE];        //Node* 를 이용하여 사이즈가 20인 큐 생성
int front = -1;                     //큐를 비움
int rear = -1;                      //큐를 비움



int initializeBST(Node** h);        //트리를 초기화하는 함수
void recursiveInorder(Node* ptr);   //순환적 중위순회하는 함수
int insert(Node* head, int key);    //트리에 노드를 추가하는 함수
int freeBST(Node* head);            //트리에 할당된 메모리를 해제하는 함수

void iterativeInorder(Node* ptr);   //반복적 중위순회하는 함수
void levelOrder(Node* ptr);         //트리의 레벨에 따라 순회하는 함수
int deleteNode(Node* head, int key);    //트리의 노드를 삭제하는 함수   
Node* pop();                //스택에서 값을 빼내는 함수
void push(Node* aNode);     //스택에 값을 넣는 함수
Node* deQueue();            //큐에서 값을 빼내는 함수
void enQueue(Node* aNode);  //큐에 값을 넣는 함수

void printStack();          //스택을 프린트 하는 함수

int main() {
	char command;           //char형의 command 생성
	int key;                //int형의 key 생성
	Node* head = NULL;      //Node* 의 head 선언

	do{
        //반복 출력
		printf("\n\n");
		printf("-----------[2021024037]-----------------[Kimheeyoung]-----------\n");
		printf("                   Binary Search Tree #2                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize BST       = z      Print Stack                  = p \n");
		printf(" Insert Node          = i      Delete Node                  = d \n");
		printf(" Recursive Inorder    = r      Iterative Inorder (Stack)    = t \n");
		printf(" Level Order (Queue)  = l      Quit                         = q \n");
        printf(" iterativeInorder     = t                                       \n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);     //사용자로부터 command값을 입력받음

		switch(command) {       //command의 값에 따라
		case 'z': case 'Z':     //만약 Z나 z를 입력받을 경우
			initializeBST(&head);   //트리를 초기화하는 함수 실행
			break;

		case 'q': case 'Q':     //Q나 q를 입력받을 경우
			freeBST(head);      //트리에 할당된 메모리를 해제하는 함수 실행
			break;

		case 'i': case 'I':     //I나 i를 입력받을 경우
			printf("Your Key = ");  //사용자로부터 추가할 값을 입력받음
			scanf("%d", &key);
			insert(head, key);      //노드를 추가하는 함수 실행
			break;

		case 'd': case 'D':     //D나 d를 입력받을 경우  
			printf("Your Key = ");  //사용자로부터 삭제할 값을 입력받음
			scanf("%d", &key);      
			deleteNode(head, key);  //노드를 삭제하는 함수 실행
			break;

		case 'r': case 'R':     //R이나 r을 입력받을 경우
			recursiveInorder(head->left);   //순환적 중위순회를 하는 함수 실행
			break;

		case 't': case 'T':     //T나 t를 입력받을 경우
			iterativeInorder(head->left);   //반복적 중위순회를 하는 함수 실행
			break;

		case 'l': case 'L':     //I나 i를 입력받을 경우
			levelOrder(head->left);     //레벌 순회 함수 실행
			break;

		case 'p': case 'P':     //P나 p를 입력받을 경우
			printStack();       //스택을 프린트 하는 함수 실행
			break;

		default:                //그 외의 경우
            //다음 문구 출력

			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');       //Q나 q가 입력될때 까지 반복

	return 1;
}


int initializeBST(Node** h) {
    //트리를 초기화하는 함수

	if(*h != NULL)
		freeBST(*h);
       //만야 트리가 비어있지 않다면, 트리의 메모리 할당 해제 

	//헤드 노드 생성
    *h = (Node*)malloc(sizeof(Node));   //*h에 메모리 할당
	(*h)->left = NULL;	   //h의 left를 NULL로 초기화
	(*h)->right = *h;       //h의 right가 *h를 가르키도록
	(*h)->key = -9999;      //h의 key값을 -9999로 설정

	top = -1;               //비어줌

	front = rear = -1;      //비어줌

	return 1;
}



void recursiveInorder(Node* ptr) {
    //순회적 중위순회 하는 함수

	if(ptr) {
        //ptr 이 가능하다면 반복

		recursiveInorder(ptr->left);    
        //ptr의 left로 순회적 중위순회하는 함수 실행
		printf(" [%d] ", ptr->key);
        //ptr의 key 값 프린트
		recursiveInorder(ptr->right);
        //ptr의 right로 순회적 중위순회하는 함수 실행
	}
}


void iterativeInorder(Node* node) {
    //반복적으로 중위순회하는 함수

	for(;;)
	{
		for(; node; node = node->left)
        //node의 left로 계속 이동하며
			push(node);     //해당 값을 node에 push
		node = pop();
        //더 이상 node의 left가 존재하지 않을 때, pop

		if(!node) 
            break;
            //만약 노드가 비어있다면 break

		printf(" [%d] ", node->key);
        //노드의 key 값 출력

		node = node->right;
        //node의 right로 이동
	}
}


void levelOrder(Node* ptr) {
    //트리를 노드의 레벨 별로 순회하는 함수

	if(!ptr)    //만약 트리가 비어있을 경우 중단
        return;

	for(;;) {
		ptr = deQueue();
        //deQueud한 값을 ptr에 대입

		if(ptr) {
            //ptr이 가능하다면 반복

			printf(" [%d] ", ptr->key);
            //ptr의 key 값을 출력

			if(ptr->left)
				enQueue(ptr->left);
                //만약 ptr의 left가 존재한다면, ptr의 left를 매개변수로 enQueue 실행

			if(ptr->right)
				enQueue(ptr->right);
                //만약 ptr의 right가 존재한다면, ptr의 right를 매개변수로 enQueue 실행
		}

		else    //그 외의 경우라면 중단
			break;

	}

}


int insert(Node* head, int key) {
    //트리에 노드를 추가하는 함수

	Node* newNode = (Node*)malloc(sizeof(Node));
    //newNode 생성 후 메모리 할당
	newNode->key = key;        
    //newNode의 key 값에 사용자가 입력한 추가하고자 하는 값 대입
	newNode->left = NULL;
    //newNode의 left값을 NULL로 초기화
	newNode->right = NULL;
    //newNode의 right값을 NULL로 초기화

	if (head->left == NULL) {
        //만약 head의 left가 NULL이면

		head->left = newNode;
        //head의 left에 newNode 삽입

		return 1;
	}

	
	Node* ptr = head->left;
    //ptr에 head의 left 대입

	Node* parentNode = NULL;        //Node의 parentNode를 생성 후 NULL로 초기화

	while(ptr != NULL) {
        //ptr이 NULL이 아니면 반복

		if(ptr->key == key) 
            return 1;
        //만약 추가하고자 하는 값이 이미 존재하나면 중단

		//나중에 부모 노드를 사용하기 위해 ptr의 값을 parentNode에 저장
		parentNode = ptr;

		
		if(ptr->key < key)
			ptr = ptr->right;
            //만약 현재의 노드 값이 추가하고자 하는 값보다 작다면
            //오른쪽 자식으로 추가

		else
			ptr = ptr->left;
            //만약  현재의 노드 값이 추가하고자 하는 값보다 크다면
            //왼쪽 자식으로 추가
	}

	//새로 추가한 노드를 부모 노드와 연결
	if(parentNode->key > key)
		parentNode->left = newNode;
        //만약 부모노드의 키가 추가하고자 하는 값보다 크다면
        //부모의 왼쪽 자식에 newNode 저장

	else
		parentNode->right = newNode;
        //만약 부모노드의 키가 추가하고자 하는 값보다 작다면
        //부모의 오른쪽 자식에 newNode 저장
	return 1;
}


int deleteNode(Node* head, int key) {
    //노드를 삭제하는 함수

	if (head == NULL) {
		printf("\n Nothing to delete!!\n");
        //만약 트리가 비어있다면 위의 문구 출력

		return -1;
	}

	if (head->left == NULL) {
		printf("\n Nothing to delete!!\n");
        //만약 head의 left가 NULL 값이라면 

		return -1;
	}

	
	Node* root = head->left;        //head의 left를 root에 저장
	Node* parent = NULL;            //parent 생성 후 NULL로 초기화
	Node* ptr = root;               //ptr 생성 후 root 값 대입

	while((ptr != NULL)&&(ptr->key != key)) {
        //ptr이 NULL이 아니고, ptr의 Key 값이 삭제하고자 하는 값이 아닌 경우

		if(ptr->key != key) {
            //만약 ptr의 key 값이 삭제하고자 하는 값이 아니면

			parent = ptr;       //부모 노드의 값을 저장

			if(ptr->key > key)
				ptr = ptr->left;
                //만약 ptr의 key 값이 삭제하고자 하는 값보다 크다면
                //ptr의 left로 이동

			else
				ptr = ptr->right;
                //만약 ptr의 key 값이 삭제하고자 하는 값보다 작다면
                //ptr의 right로 이동
		}
	}

	
	if(ptr == NULL) {
		printf("No node for key [%d]\n ", key);
        //삭제하고자 하는 값이 없다면 위의 문구 출력

		return -1;
	}

	
	if(ptr->left == NULL && ptr->right == NULL) {
        //만약 리프노드를 삭제한다면

		if(parent != NULL) {
            //부모노드가 존재한다면

			if(parent->left == ptr)
				parent->left = NULL;
                //parent의 left가 ptr과 같다면
                //parent의 left 값 삭제

			else
				parent->right = NULL;
                //parent의 right가 ptr과 같다면
                //parent의 right 값 삭제

		} 
        
        else {
            head->left = NULL;
            //parent가 NULL일 경우, 삭제될 노드가 루트
            //head의 left 값 삭제
		}

		free(ptr);      //ptr의 메모리 할당 해제
        
		return 1;
	}

	
	if ((ptr->left == NULL || ptr->right == NULL)) {
        //만약 삭제할 노드가 하나의 자식을 가지고 있다면

		Node* child;        //Node* 의 child 생성

		if (ptr->left != NULL)
			child = ptr->left;
            //ptr의 left가 NULL이 아니라면, ptr의 left값을 child에 저장

		else
			child = ptr->right;
            //ptr의 right가 NULL이 아니라면, ptr의 right값을 child에 저장

		if(parent != NULL) {
            //만약 부모노드가 NULL이 아니라면

			if(parent->left == ptr)
				parent->left = child;
                //parent의 left가 ptr 과 같다면
                //parent의 left에 child 값 대입

			else
				parent->right = child;
                //parent의 right가 ptr 과 같다면
                //parent의 right에 chile 값 대입

		} 
        
        else {
            //parent가 NULL일 경우, 삭제 될 노드는 루트이며 하나의 자식을 가짐
            
			root = child;       //child를 root로 만듦
		}

		free(ptr);      //ptr의 메모리 할당 해제

		return 1;
	}



    //노드가 두개의 자식을 가지고 있을 경우

	Node* candidate;        //candidate 생성
	parent = ptr;           //ptr의 값을 parent에 저장


	candidate = ptr->right; //ptr의 right값을 candidate에 저장


	//가장 작은 노드를 찾아서 이동
	while(candidate->left != NULL) {
        //candidate에서 left가 없을 때 까지 반복

        parent = candidate;     //parent에 candidate 값 대입
		candidate = candidate->left;    //candidate 값을 candidate의 left로 갱신
	}

	
	if (parent->right == candidate)
		parent->right = candidate->right;
        //parent의 right가 candidate와 같다면
        //parent의 right에 candidate의 right값 대입

	else
		parent->left = candidate->right;
        //parent의 left가 candidate와 같다면
        //parent의 left에 candidate의 left값 대입 

	ptr->key = candidate->key;
    //ptr의 key에 candidate의 key 값 대입

	free(candidate);

	return 1;
}


void freeNode(Node* ptr) {
    //노드의 메모리 할당을 해제하는 함수

	if(ptr) {
        //만약 ptr이 존재한다면

		freeNode(ptr->left);
        //ptr의 left에 대하여 메모리 할당 해제
		freeNode(ptr->right);
        //ptr의 right에 대하여 메모리 할당 해제
		free(ptr);  //ptr 메모리 할당 해제
	}
}


int freeBST(Node* head) {
    //트리의 메모리 할당을 해제하는 함수

	if(head->left == head) {
        //만약 노드가 하나라면

		free(head);     //head의 메모리 할당 해제

		return 1;
	}

	Node* p = head->left;   //Node *p 생성 후, head의 left 값 대입

	freeNode(p);    //p의 freeNode 실행

	free(head);     //head의 메모리 할당 해제

	return 1;
}


Node* pop() {
    //스택에 있는 값을 꺼내는 함수

	if (top < 0) 
        return NULL;
        //만약 스택이 비어있으면 NULL 리턴

	return stack[top--];        //스택에서 하나를 꺼냄
}


void push(Node* aNode) {
    //스택에 값을 넣는 함수

	stack[++top] = aNode;       //새로운 값을 스택에 추가함
}


void printStack() {
    //스택을 프린트 하는 함수

   	int i = 0;      //int형 변수 선언

	printf("--- stack ---\n");
	while(i <= top) {
        //스택에 있는 값이 남아있을 때 까지

		printf("stack[%d] = %d\n", i, stack[i]->key);
        //번호와 함께 스택안에 있는 값 출력
	}
}


Node* deQueue() {
    //큐에서 값을 꺼내는 함수

	if (front == rear) {
		printf("\n....Now Queue is empty!!\n" );
        //큐의 front와 rear이 같을 경우 (큐가 비어있을 경우)

		return NULL;
	}

	front = (front + 1) % MAX_QUEUE_SIZE;
    //front을 값에 1을 더하고, 큐의 MAX 사이즈와의 나머지를 구하여 front에 대입

	return queue[front];
}


void enQueue(Node* aNode) {
    //큐에 값을 넣는 함수

	rear = (rear + 1) % MAX_QUEUE_SIZE;
    //rear의 값에 1을 더하고, 큐의 MAX 사이즈와의 나머지를 구하여 rear에 대입
	if (front == rear) {
		printf("\n....Now Queue is full!!\n");
        //큐의 front와 rear이 값을 경우 (큐가 가득 차 있을 경우)

		return;
	}

	queue[rear] = aNode;        //큐의 rear자리에 새로운 값 추가
}