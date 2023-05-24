#include <stdio.h>
#include <stdlib.h>

typedef struct node {       //구조체 선언
	int key;                //노드의 데이터를 담는 정수형 변수 key
	struct node *left;      //노드의 왼쪽 포인터 left
	struct node *right;     //노드의 오른쪽 포인터 right
} Node;

int initializeBST(Node** h);        //리스트를 초기화하는 함수


//사용할 함수 정의
void inorderTraversal(Node* ptr);       //중위순회하는 함수 (왼쪽 -> 부모 -> 자식)
void preorderTraversal(Node* ptr);      //전위순회하는 함수 (부모 -> 왼쪽 -> 오른쪽)
void postorderTraversal(Node* ptr);     //후위순회하는 함수 (왼쪽 -> 오른쪽 -> 부모)
int insert(Node* head, int key);        //트리에 노드를 추가하는 함수
int deleteLeafNode(Node* head, int key);    //리프노드를 삭제하는 함수
Node* searchRecursive(Node* ptr, int key);  //재귀적 방식을 이용하여 노드를 탐색하는 함수
Node* searchIterative(Node* head, int key); //반복하는 방식을 이용하여 노드를 탐색하는 함수
int freeBST(Node* head);                    //트리에 할당된 모든 메모리 해제


int main() {
	char command;       //char형의 변수 command 선언
	int key;            //int형의 변수 key  선언
	Node* head = NULL;  //Node* head를 선언 후 NULL로 초기화
	Node* ptr = NULL;	//Node* ptr을 선언 후 NULL로 초기화 (temp의 역할)

	do{                                                                                     //반복
		printf("\n\n");
		printf("---------------[2021024037]--------[Kimheeyoung]----------------\n");       //나의 학번과 이름 출력
		printf("                   Binary Search Tree #1                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize BST       = z                                       \n");
		printf(" Insert Node          = n      Delete Leaf Node             = d \n");
		printf(" Inorder Traversal    = i      Search Node Recursively      = s \n");
		printf(" Preorder Traversal   = p      Search Node Iteratively      = f\n");
		printf(" Postorder Traversal  = t      Quit                         = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);             //사용자로부터 command 값을 입력받음

		switch(command) {           //입력받은 command 값에 따라 실행

		case 'z': case 'Z':         //z나 Z를 입력받을 경우
			initializeBST(&head);   //트리를 초기화하는 함수 실행
			break;              

		case 'q': case 'Q':         //q나 Q를 입력받을 경우
			freeBST(head);          //트리에 할당된 메모리를 해제하는 함수 실행
			break;  

		case 'n': case 'N':         //n이나 N을 입력받을 경우
			printf("Your Key = ");  
			scanf("%d", &key);      //사용자로부터 트리에 추가할 노드 값을 입력받음
			insert(head, key);      //트리에 노드를 추가하는 함수 실행
			break;

		case 'd': case 'D':         //d나 D를 입력받을 경우
			printf("Your Key = ");
			scanf("%d", &key);      //사용자로부터 트리에서 삭제할 노드 값을 입력받음    
			deleteLeafNode(head, key);  //트리의 노드를 삭제하는 함수 실행
			break;

		case 'f': case 'F':         //f나 F를 입력받을 경우
			printf("Your Key = ");
			scanf("%d", &key);      //사용자로부터 탐색할 노드 값을 입력받음

			ptr = searchIterative(head, key);   //반복하는 방식으로 트리를 탐색하는 함수를 실행 후, 결과값을 ptr에 저장

			if(ptr != NULL)             //민액 헤당 노드를 찾았다면
				printf("\n node [%d] found at %p\n", ptr->key, ptr);    //해당 메세지 출력

			else                        //만약 해당 노드를 찾지 못했다면
				printf("\n Cannot find the node [%d]\n", key);          //해당 메세지 출력

			break;

		case 's': case 'S':         //s나 S를 입력받을 경우             
			printf("Your Key = ");
			scanf("%d", &key);      //사용자로부터 탐색할 노드 값을 입력받음

			ptr = searchRecursive(head->left, key);     //재귀적 방식을 이용하여 노드를 탐색하는 함수를 실행 후, 결과값을 ptr에 저장

			if(ptr != NULL)             //만약 해당 노드를 찾았다면
				printf("\n node [%d] found at %p\n", ptr->key, ptr);    //해당 메세지 출력   
			
            else                        //만약 해당 노드를 찾지 못했다면
				printf("\n Cannot find the node [%d]\n", key);          //해당 메세지 출력
			break;

		case 'i': case 'I':        //i나 I를 입력받을 경우     
			inorderTraversal(head->left);   //트리를 중위순회하는 함수 실행 
			break;

		case 'p': case 'P':         //p나 P를 입력받을 경우
			preorderTraversal(head->left);  //트리를 전위순회하는 함수 실행
			break;

		case 't': case 'T':         //t나 T를 입력받을 경우
			postorderTraversal(head->left); //트리를 후위순회하는 함수 실행
			break;

		default:                    //그 외의 경우
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");      //해당 메세지 출력
			break;
		}

	}while(command != 'q' && command != 'Q');       //command 값으로 q나 Q가 입력될때까지 반복

	return 1;
}


int initializeBST(Node** h) {
    //트리를 초기화하는 함수

	if(*h != NULL)          //만약 트리가 비어있지 않다면
		freeBST(*h);        //트리 내의 메모리 할당 해제

	//헤드 노드 생성
	*h = (Node*)malloc(sizeof(Node));   //*h에 메모리 할당
	(*h)->left = NULL;	                //루트 노드이기 때문에 left는 NULL
	(*h)->right = *h;                   //right가 자기 자신을 가르키도록    
	(*h)->key = -9999;                  //노드 안에 -9999라는 수 저장

	return 1;
}


void inorderTraversal(Node* ptr) {
    //트리를 중위순회하는 함수

	if(ptr) {
		inorderTraversal(ptr->left);    //해당 노드의 left를 매개변수로 하여 트리를 중위순회하는 함수 다시 호출
		printf(" [%d] ", ptr->key);     //노드의 값 출력 (더이상 이동 할 왼쪽 노드가 없을 때)
		inorderTraversal(ptr->right);   //노드의 right를 매개변수로 하여 중위순회하는 함수 호출 (해당 노드의 부모 출력)
	}
}


void preorderTraversal(Node* ptr) {
    //트리를 전위순회하는 함수

	if(ptr) {
		printf(" [%d] ", ptr->key);         //부모 노드 먼저 출력하기에, ptr의 key 갑 출력
		preorderTraversal(ptr->left);       //해당 노드의 left를 매개변수로 하여 트리를 전위순회하는 함수 다시 호출
		preorderTraversal(ptr->right);      
        //왼쪽 노드에 더이상 이동할 곳이 없으면, right를 매개변수로 하여 트리를 전위순회하는 함수 다시 호출
	}
}


void postorderTraversal(Node* ptr) {
    //트리를 후위순회하는 함수

	if(ptr) {
		postorderTraversal(ptr->left);      //해당 노드의 left로 계속 이동하며 트리를 후위순회하는 함수 재호출
		postorderTraversal(ptr->right);     
        //더이상 해당 노드의 왼쪽 자식이 없을때, 계속 right로 이동하며 트리를 후위순회하는 함수 재호출    
		printf(" [%d] ", ptr->key);         //왼쪽자식, 오른쪽 자식, 부모 노드 순서대로 출력되게 됨
	}
}


int insert(Node* head, int key) {
    //트리에 노드를 추가하는 함수

	Node* newNode = (Node*)malloc(sizeof(Node));    //newnode 생성 후 메모리 할당

	newNode->key = key;     //newnode의 key값에 새로 추가하고자 하는 값 저장
	newNode->left = NULL;   //newnode의 left를 NULL로 초기화
	newNode->right = NULL;  //newnode의 right를 NULL로 초기화


	if (head->left == NULL) {
        //만약 head의 left가 비어있다면

		head->left = newNode;       //head의 left에 newnode 삽입

        return 1;
	}

	
    //만약 head의 left가 루트노드라면
	Node* ptr = head->left;     //ptr에 head의 left 저장
	Node* parentNode = NULL;    //parentNode 생성 후 NULL로 초기화

	while(ptr != NULL) {
        //리프노드까지 올 때 까지 반복

		if(ptr->key == key)     //만약 트리 안에 이미 같은 노드가 있다면  중단
            return 1;   

		//부모노드를 갱신 및 저장
		parentNode = ptr;

		if(ptr->key < key)      //만약 현재 노드가 추가하는 노드 값보다 작을 경우
			ptr = ptr->right;   //현재 노드를 right로 이동

		else                    //만약 현재 노드가 추가하는 노드 값보다 클 경우
			ptr = ptr->left;    //현재 노드를 left로 이동
	}

	//노드의 위치 확정하기
	if(parentNode->key > key)   //만약 부모노드의 값이 추가하는 노드 값보다 클 경우
		parentNode->left = newNode;     //부모노드의 left로 추가하는 노드 삽입

	else                        //만약 부모노드의 값이 추가하는 노드 값보다 작을 경우    
		parentNode->right = newNode;    //부모노드의 right로 추가하는 노드 삽입

	return 1;
}


int deleteLeafNode(Node* head, int key) {
    //리프노드를 삭제하는 함수

	if (head == NULL) {
        //만약 트리가 비어있다면

		printf("\n Nothing to delete!!\n");         //삭제할 노드가 없음을 알리는 메세지 출력

		return -1;
	}

	if (head->left == NULL) {
        //만약 트리의 노드가 하나라면 (루트노드)

		printf("\n Nothing to delete!!\n");         //삭제할 노드가 없음을 알리는 메세지 출력

		return -1;
	}


	//위의 두 경우가 아닐 경우

	Node* ptr = head->left;     //ptr에 head노드의 left 대입


	//노드 삭제와 함께 다른 노드들의 연결 정리
	Node* parentNode = head;    //삭제할 노드의 부모노드를 저장하는 parentNode 생성

	while(ptr != NULL) {    
        //ptr을 이동하여 더이상 갈 수 없는 끝가지 갈 때 까지 반복

		if(ptr->key == key) {       //ptr의 값이 삭제하고자하는 리프노드의 값과 같다면

			if(ptr->left == NULL && ptr->right == NULL) {       
                //만약 ptr의 left가 NULL값이고, ptr의 right가 NULL 값이면
				
				if(parentNode == head)      //부모 노드가 head와 같을 경우 (ptr이 루트 노드 일 경우)
					head->left = NULL;      //head의 left 값을 NULL로 초기화

				
				if(parentNode->left == ptr) //부모노드의 left가 ptr과 같을 경우
					parentNode->left = NULL;    //부모노드의 left를 NULL로 초기화

				else                        //부모노드의 right가 ptr과 같을 경우
					parentNode->right = NULL;   //부모노드의 right를 NULL로 초기화

				free(ptr);          //ptr 메모리 해제
			}

			else {         
                //만약 ptr의 left와 right가 모두 NULL이 아닐경우

				printf("the node [%d] is not a leaf \n", ptr->key);     //해당 노드는 리프노드가 아님
			}
			return 1;
		}

		
        //ptr의 key값과 삭제하고자 하는 값이 같지 않다면
		parentNode = ptr;       //ptr의 값을 부모노드로 저장 (부모노드의 정보 갱신 및 유지)

	
		if(ptr->key < key)      //만약 현재 노드가 삭제하고자 하는 노드보다 작다면
			ptr = ptr->right;   //현재 노드에서 right로 이동

		else                    //만약 현재 노드가 삭제하고자 하는 노드보다 크다면
			ptr = ptr->left;    //현재 노드에서 left로 이동

	}

    //트리를 모두 확인했지만, 삭제하고자 하는 노드를 찾지 못한 경우
	printf("Cannot find the node for key [%d]\n ", key);    //해당 메세지 출력

	return 1;
}


Node* searchRecursive(Node* ptr, int key) {
    //트리를 재귀적인 용법을 사용하여 탐색

	if(ptr == NULL)     //만약 트리가 비어있을 경우
		return NULL;

	if(ptr->key < key)  //현재 노드의 값이 탐색하고자 하는 값보다 작다면
		ptr = searchRecursive(ptr->right, key);     
        //현재 노드를 오른쪽으로 이동하여 다시 searchRecursive를 호출한 후, 결과값을 ptr에 저장

	else if(ptr->key > key)     //현재 노드의 값이 탐색하고자 하는 값보다 크다면
		ptr = searchRecursive(ptr->left, key);
        //현재 노드를 왼쪽으로 이동하여 다시 searchRecursive를 호출한 후, 결과값을 ptr에 저장


	//탐색하고자 하는 노드값을 찾으면 해당 값 리턴
	return ptr;

}


Node* searchIterative(Node* head, int key) {
    //트리를 반복적인 용법을 사용하여 탐색

	Node* ptr = head->left;     //ptr에 head의 left 저장

	while(ptr != NULL) {    
        //head의 left가 NULL 값이 아니면 계속 반복 (리프노드까지 도착할 때 까지)

		if(ptr->key == key)         //만약 현재노드의 값이 탐색하고자 하는 값과 같다면
			return ptr;         //현재 노드의 값 출력

		if(ptr->key < key)          //만약 현재노드의 값이 탐색하고자 하는 값보다 작다면
            ptr = ptr->right;       //현재 노드를 right로 이동

		else                        //만약 현재노드의 값이 탐색하고자 하는 값보다 크다면
			ptr = ptr->left;        //현재 노드를 left로 이동
	}

	return NULL;
}


void freeNode(Node* ptr) {
    //트리 안의 모든 노드에 대하여 메모리 해제하는 함수

	if(ptr) {
		freeNode(ptr->left);        //ptr의 left 노드에 대하여 메모리 해제
		freeNode(ptr->right);       //ptr의 right 노드에 대하여 메모리 해제

		free(ptr);                  //prt노드에 대하여 메모리 해제
	}
}


int freeBST(Node* head) {
    //트리에 할당된 메모리를 해제하는 함수

	if(head->left == head) {
        //만약 트리에 노드가 하나밖에 없다면

		free(head); //해당 노드의 메모리 할당 해제

		return 1;
	}

    //트리에 노드가 2개 이상일 경우
	Node* p = head->left;       //해당 노드의 left를 Node* p에 대입

	freeNode(p);                //루트 노드를 제외한 노드 메모리 할당 해제

	free(head);                 //루트 노드 메모리 할당 해제

	return 1;
}