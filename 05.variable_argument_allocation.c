#include <stdio.h>
#include <stdlib.h>

int* allocate(int num, ...);

int main()
{
	int a = 4, b = 8;
	int* p = NULL;

	p = allocate(1, a);			// 포인터 함수를 이용하여 p가 allocate로 부터 동적 할당을 받는다.
	p[0] = 10;					// p는 동적 할당이 되었고, 첫번째 위치에 10을 저장;
	printf("4byte 힙 영역에 저장된 값 : %d\n", p[0]);

	free(p);
	p = NULL;
}

int* allocate(int num, ...)
{
	int* p = &num + 1;				// p의 위치는 num의 바로 다음 위치로 선언
	static int* heap = NULL;		// heap 변수를 정적으로 선언하여 함수를 return 해도 heap의 정보가 사라지지 않게 한다.

	if (1 == num)
	{
		heap = (int*)malloc(p[0]);	// heap 변수에 동적 할당한다는 정보를 넣는다.
		return heap;				// 동적 할당한다는 정보를 return 한다.
	}
	else
	{
		printf("인자의 개수는 1개 이하입니다.\n");
		return NULL;
	}
}
// 11번째 줄
// 포인터 변수 p에 allocate 포인터 함수를 이용하여 동적 할당을 하고 있다.

// 12번째 줄
// 동적 할당된 p의 첫번째 위치에 10을 저장

// 21번째 줄
// p의 위치는 num의 바로 다음 위치로 선언
// num의 바로 뒤부터 가변 인자로 받아들인 값들을 차례로 저장한다.

// 22번째 줄
// heap 변수에 동적 할당을 한다는 정보를 넣기 위해 선언을 한다.
// return 해도 heap의 정보가 사라지지 않게 한다.

// 26번째 줄
// heap 변수에 동적 할당을 한다는 정보를 넣는다.

// 27번째 줄
// 동적 할당한다는 정보를 return 한다.
// 이 순간 p, num에 대한 정보는 사라지게 되며 heap은 함수가 제거되도 남아서 heap의 정보를 return 한다.