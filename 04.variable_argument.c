#include <stdio.h>

void add(int num, ...);			// 가변 인자의 선언

int main()
{
	int a = 10, b = 20, c = 30;

	add(1, a);
	add(2, a, b);
	add(3, a, b, c);
}

void add(int num, ...)			// 가변 인자의 정의
{
	int* p = &num + 1;			// 매개변수 저장 방법

	if (1 == num)
		printf("%d\n", p[0]);
	else if( 2 == num)
		printf("%d\n", p[0] + p[1]);
	else
		printf("%d\n", p[0] + p[1] + p[2]);
}
// 3번째 줄
// 매개 변수를 ...으로 받는다.
// 이는 변수를 무엇이나 받는다는 뜻이다.
// 템플릿에도 나오니 참고하도록

// 16번째 줄
// 첫번째 변수 num을 시작으로 배열처럼 차례로 받은 변수들을 차례로 저장한다.