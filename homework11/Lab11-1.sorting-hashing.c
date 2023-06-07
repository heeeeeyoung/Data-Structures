#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ARRAY_SIZE			13	/* prime number */
#define MAX_HASH_TABLE_SIZE 	MAX_ARRAY_SIZE


//사용할 함수 정의
int initialize(int **a);
int freeArray(int *a);
void printArray(int *a);

int selectionSort(int *a);
int insertionSort(int *a);
int bubbleSort(int *a);
int shellSort(int *a);
int quickSort(int *a, int n);

int hashCode(int key);
int hashing(int *a, int **ht);
int search(int *ht, int key);


int main() {
	char command;   //char형의 변수 command 생성

	int *array = NULL;
	int *hashtable = NULL;
	int key = -1;
	int index = -1;

	srand(time(NULL));  //랜덤 난수 생성 설정

	do{
		printf("-------------[2021024037]----------------[Kimheeyoung]----------\n");
		printf("                        Sorting & Hashing                       \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize       = z           Quit             = q\n");
		printf(" Selection Sort   = s           Insertion Sort   = i\n");
		printf(" Bubble Sort      = b           Shell Sort       = l\n");
		printf(" Quick Sort       = k           Print Array      = p\n");
		printf(" Hashing          = h           Search(for Hash) = e\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");       //사용자로부터 command값을 입력받음
		scanf(" %c", &command);

		switch(command) {       //command 값에 따라 실행

		case 'z': case 'Z':     //Z나 z를 입력받을 경우
			initialize(&array); //배열을 초기화하는 함수 실행
			break;

		case 'q': case 'Q':     //Q나 q를 입력받을 경우
			freeArray(array);   //배열에 할당된 메모리를 해제하는 함수 실행
			break;

		case 's': case 'S':     //S나 s를 입력받을 경우
			selectionSort(array);   //선택정렬을 하는 함수 실행
			break;

		case 'i': case 'I':     //I나 i를 입력받을 경우
			insertionSort(array);   //삽입정렬을 하는 함수 실행
			break;

		case 'b': case 'B':     //B나 b를 입력받을 경우
			bubbleSort(array);  //버블정렬을 하는 함수 실행
			break;

		case 'l': case 'L':     //L이나 l을 입력받을 경우
			shellSort(array);   //쉘정렬을 하는 함수 실행
			break;

		case 'k': case 'K':     //K나 k를 입력받을 경우
			printf("Quick Sort: \n");
			printf("----------------------------------------------------------------\n");
			printArray(array);                          //배열을 프린트 하는 함수 실행
			quickSort(array, MAX_ARRAY_SIZE);           //퀵정렬을 하는 함수 실행
			printf("----------------------------------------------------------------\n");
			printArray(array);      //배열을 프린트 하는 함수 실행
			break;

		case 'h': case 'H':     //H나 h를 입력받을 경우
			printf("Hashing: \n");
			printf("----------------------------------------------------------------\n");
			printArray(array);          //배열을 프린트 하는 함수 실행
			hashing(array, &hashtable);     //해싱함수 실행
			printArray(hashtable);      //배열을 프린트 하는 함수 실행
			break;

		case 'e': case 'E':     //E나 e를 입력받을 경우
			printf("Your Key = ");  //사용자로부터 탐색할 값을 입력받음
			scanf("%d", &key);
			printArray(hashtable);      //배열을 출력하는 함수 실행
			index = search(hashtable, key);     //특정 값을 탐색하는 함수 실행
			printf("key = %d, index = %d,  hashtable[%d] = %d\n", key, index, index, hashtable[index]);
            //탐색한 결과를 출력
			break;

		case 'p': case 'P':     //P나 p를 입력받을 경우
			printArray(array);  //배열을 출력하는 함수 실행
			break;

		default:        //그 외의 경우
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');   //command값이 Q나 q가 입력될 때 까지 반복

	return 1;
}


int initialize(int** a) {
    //배열을 초기화하는 함수

	int *temp = NULL;   //*temp 생성후 NULL로 초기화

	if(*a == NULL) {    //만약 배열이 비어있다면
		temp = (int*)malloc(sizeof(int) * MAX_ARRAY_SIZE);  //temp에 메모리 할당
		*a = temp;  //*a에 temp 대입
	} 
    
    else
		temp = *a;      //배열이 비어있지 않다면, *a의 값을 temp로 대입

	for(int i = 0; i < MAX_ARRAY_SIZE; i++)
		temp[i] = rand() % MAX_ARRAY_SIZE;
        //temp 배열 처음부터 끝까지 랜덤값 배정

	return 0;
}


int freeArray(int *a) {
    //배열에 할당된 메모리를 해제하는 함수

	if(a != NULL)   //만약 배열이 비어있지 않다면
		free(a);    //배열에 할당된 메모리 해제

	return 0;
}


void printArray(int *a) {
    //배열을 출력하는 함수

	if (a == NULL) {    //만약 배열이 비어있다면
		printf("nothing to print.\n");  //출력할것이 없음
		return;
	}

    //배열이 비어있지 않다면
	for(int i = 0; i < MAX_ARRAY_SIZE; i++)
		printf("a[%02d] ", i);      //배열의 인덱스 번호 출력
	printf("\n");

	for(int i = 0; i < MAX_ARRAY_SIZE; i++)
		printf("%5d ", a[i]);       //배열 내의 원소 모두 출력
	printf("\n");
}


int selectionSort(int *a) {
    //선택정렬 함수

	int min;
	int minindex;
	int i, j;

	printf("Selection Sort: \n");
	printf("----------------------------------------------------------------\n");

	printArray(a);      //배열을 출력하는 함수 실행

	for (i = 0; i < MAX_ARRAY_SIZE; i++) {
		minindex = i;   //i를 minindex로 설정
		min = a[i];     //배열의 i번째 원소를 최소값으로 설정

		for(j = i+1; j < MAX_ARRAY_SIZE; j++) {
			if (min > a[j]) {   //만약 최소값보다 더 작은 값을 찾게되면
				min = a[j];     //해당 값을 최소값으로 설정
				minindex = j;   //해당 값의 인덱스를 minindex로 설정
			}
		}

		a[minindex] = a[i];     //최종으로 정해진 가장 작은 값을 최소값으로 설정하며 앞에서부터 채워넣음
		a[i] = min;             
	}

	printf("----------------------------------------------------------------\n");
	printArray(a);      //배열을 출력하는 함수 실행

	return 0;
}


int insertionSort(int *a) {
    //삽입정렬하는 함수

	int i, j, t;

	printf("Insertion Sort: \n");
	printf("----------------------------------------------------------------\n");

	printArray(a);      //배열을 출력하는 함수 실행

	for(i = 1; i < MAX_ARRAY_SIZE; i++) {
		t = a[i];
		j = i;

		while (a[j-1] > t && j > 0) {
            //지정된 인덱스 앞에 더 큰 값이 있다면

			a[j] = a[j-1];  //자리를 바꿈
			j--;    
		}

		a[j] = t;   //더이상 지정된 인덱스 앞에 더 큰 값이 없다면, t의 값으로 유지
	}

	printf("----------------------------------------------------------------\n");
	printArray(a);      //배열을 출력하는 함수 실행

	return 0;
}


int bubbleSort(int *a) {
    //버블정렬하는 함수

	int i, j, t;

	printf("Bubble Sort: \n");
	printf("----------------------------------------------------------------\n");

	printArray(a);      //배열을 출력하는 함수 실행

	for(i = 0; i < MAX_ARRAY_SIZE; i++) {
		for (j = 0; j < MAX_ARRAY_SIZE; j++) {
			if (a[j-1] > a[j]) {
                //지정된 인덱스 앞에 더 큰 값이 있다면

				t = a[j-1];         //더 큰 값을 t에 저장
				a[j-1] = a[j];      //지정된 인덱스의 값을 앞으로 당김
				a[j] = t;           //t에 저장된 값을 지정된 인덱스로 대입
			}
		}
	}

	printf("----------------------------------------------------------------\n");
	printArray(a);      //배열을 출력하는 함수 실행

	return 0;
}


int shellSort(int *a) {
    //쉘정렬을 하는 함수

	int i, j, k, h, v;

	printf("Shell Sort: \n");
	printf("----------------------------------------------------------------\n");

	printArray(a);      //배열을 출력하는 함수 실행

	for (h = MAX_ARRAY_SIZE/2; h > 0; h /= 2) { 
        //배열을 반으로
		for (i = 0; i < h; i++) {   
            //배열의 왼쪽처음부터
			for(j = i + h; j < MAX_ARRAY_SIZE; j += h) {
                //배열의 오른쪽 처음부터
				v = a[j];
				k = j;
				while (k > h-1 && a[k-h] > v) {
                    //k가 h-1보다 크고, 오른쪽 원소보다 왼쪽 원소가 더 크다면
					a[k] = a[k-h];  //왼쪽원소를 오른쪽으로 대입
					k -= h;     //k=k-h로 설정
				}
				a[k] = v;   //왼쪽에 오른쪽 원소 대입
			}
		}
	}
	printf("----------------------------------------------------------------\n");
	printArray(a);      //배열을 프린트하는 함수

	return 0;
}


int quickSort(int *a, int n) {
    //퀵정렬 하는 함수

	int v, t;
	int i, j;

	if (n > 1) {
		v = a[n-1];
		i = -1;
		j = n - 1;

		while(1) {
			while(a[++i] < v);      //배열의 왼쪽은 기준값보다 작아야함
			while(a[--j] > v);      //배열의 오른쪽은 기준값보다 커야함

			if (i >= j) break;      //i가 j와 같아지거나 커지면
			t = a[i];           //두 원소의 값 바꿈
			a[i] = a[j];
			a[j] = t;
		}

		t = a[i];           //while루프 종류 후, 두 원소의 값 바꿈
		a[i] = a[n-1];
		a[n-1] = t;

		quickSort(a, i);        //퀵정렬을 하는 함수 실행
		quickSort(a+i+1, n-i-1);    //퀵정렬을 하는 함수 실행
	}

	return 0;
}


int hashCode(int key) {
    //해시코드를 생성하는 함수

   return key % MAX_HASH_TABLE_SIZE;
}


int hashing(int *a, int **ht) {
    //해싱을 하는 함수

	int *hashtable = NULL;      //hashtable생성 후 NULL로 초기화

	if(*ht == NULL) {
        //만약 *ht가 NULL값일 경우

		hashtable = (int*)malloc(sizeof(int) * MAX_ARRAY_SIZE); //hashtable에 메모리 할당
		*ht = hashtable; //*ht에 hashtable 대입
	}
    
    else {  //*ht가 NULL이 아닐 경우
		hashtable = *ht;    //hashtable에 *ht 대입
	}

	for(int i = 0; i < MAX_HASH_TABLE_SIZE; i++)
		hashtable[i] = -1;      //hashtable 전체를 -1로

	int key = -1;
	int hashcode = -1;
	int index = -1;

	for (int i = 0; i < MAX_ARRAY_SIZE; i++) {
		key = a[i];                 //a[i]원소를 key값으로
		hashcode = hashCode(key);   //hashcode 생성 후 대입

		if (hashtable[hashcode] == -1){
            //만약 hashtable[hashcode]가 -1이라면
			hashtable[hashcode] = key;  
            //hashtable[hashcode]값을 key값으로 설정
		} 
        
        else {
            index = hashcode;   //hashcode값을 index로 설정하고

			while(hashtable[index] != -1) {
                //hashtable[index]값이 -1이 아니라면

				index = (++index) % MAX_HASH_TABLE_SIZE;    //index값 갱신
			}

			hashtable[index] = key;     //hashtable[index]에 key값 설정
		}
	}

	return 0;
}


int search(int *ht, int key) {
    //탐색하는 함수

	int index = hashCode(key);  //해시코드 생성 후 index에 대입

	if(ht[index] == key)    //ht[index]가 key값과 같다면
		return index;       //index값 리턴

	while(ht[++index] != key) {
        //ht[++index]가 key값과 같지 않다면
		index = index % MAX_HASH_TABLE_SIZE;        //index값 갱신
	}
    
	return index;       //index값 리턴
}