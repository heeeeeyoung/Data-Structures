#include <stdio.h>

int main() {
	int i;							// int 타입의 정수 i 선언
	int* ptr = NULL;				// int * 타입인 ptr 선언후, NULL 값으로 초기화
	int** dptr;						// int ** 타입인 dptr 선언

	i = 1234;						// 변수 i에 1234 대입

	printf("[checking values before ptr = &i] \n");				// * ptr에 &i를 대입하기 전의 값 확인
	printf("value of i == %d \n", i);							// i의 값인 1234를 출력
	printf("address of i == %p \n", &i);						// i의 주소값  출력
	printf("value of ptr == %p \n", ptr);						// ptr의 값을 출력하는데, 현재는 아무것도 가르키고 있지 않으므로 0 출력
	printf("adress of ptr == %p \n", &ptr);						// ptr의 주소값 출력
	printf("----[Kimheeyoung]---------[2021024037]---------\n");       // 나의 이름과 학번 출력


	ptr = &i;
	// * ptr is now holding the address of i							// ptr에 &i 대입


	printf("\n[checking values after ptr = &i] \n");			// ptr에 &i 를 대입한 후의 값 확인
	printf("value of i == %d \n", i);							// i의 값인 1234 출력
	printf("address of i == %p \n", &i);						// i의 주소값 출력
	printf("value of ptr == %p \n", ptr);						// ptr의 값인 i의 주소값 출력
	printf("adress of ptr == %p \n", &ptr);						// ptr의 주소값 출력
	printf("valure of *ptr == %d \n", *ptr);					// *ptr의 값인 i값 출력
	printf("----[Kimheeyoung]---------[2021024037]---------\n");       // 나의 이름과 학번 출력


	dptr = &ptr;
	// * dptr is now holding the address of ptr						// dptr에 &ptr 대입	


	printf("\n[checking values after dptr = &ptr] \n");			// dptr에 &ptr 을 대입한 후의 값 확인
	printf("value of i == %d \n", i);							// i의 값인 1234 출력
	printf("address of i == %p \n", &i);						// i의 주소값  출력
	printf("value of ptr == %p \n", ptr);						// i의 주소값  출력
	printf("adress of ptr == %p \n", &ptr);						// ptr의 주소값  출력
	printf("value of *ptr == %d \n", *ptr);						// *ptr 의 값인 i의 값 출력
	printf("value of dptr == %p \n", dptr);						// dptr의 값인 ptr의 주소값 출력
	printf("address of dptr == %p \n", &dptr);					// dptr의 주소값 출력
	printf("value of *dptr == %p \n", *dptr);					// *dptr의 값인 i의 주소값 출력
	printf("value of **dptr == %d \n", **dptr);					// **dptr의 값인 i의 값 출력
	printf("----[Kimheeyoung]---------[2021024037]---------\n");       // 나의 이름과 학번 출력


	*ptr = 7777;
	// * changing the value of *ptr										// *ptr의 값을 7777로 변경


	printf("\n[after *ptr = 7777] \n");							// *ptr의 값을 7777로 변경한 후의 값 확인
	printf("value of i == %d \n", i);							// i의 값인 7777 출력
	printf("value of *ptr == %d \n", *ptr);						// *ptr의 값인 7777 출력
	printf("value of **dptr == %d \n", **dptr);					// **dptr의 값인 7777 출력
	printf("----[Kimheeyoung]---------[2021024037]---------\n");       // 나의 이름과 학번 출력

	**dptr = 8888;
	// * changing the value of **dptr									// **dptr의 값을 8888로 변경

	printf("\n[after **dptr = 8888] \n");						// **dptr의 값을 8888로 변경한 후의 값 확인
	printf("value of i == %d \n", i);							// i의 값인 8888 출력
	printf("value of *ptr == %d \n", *ptr);						// *ptr의 값인 8888 출력
	printf("value of **dptr == %d \n", **dptr);					//**dptr의 값인 8888 출력

	return 0;													// i, *ptr, **dptr 을 출력할 경우, 값이 모두 같음
}