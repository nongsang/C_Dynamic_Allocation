#include <stdio.h>

void add(int num, ...);

int main()
{
	int a = 10, b = 20, c = 30;

	add(1, a);
	add(2, a, b);
	add(3, a, b, c);
}

void add(int num, ...)
{
	int* p = NULL;
	p = &num + 1;

	if (1 == num)
		printf("%d\n", p[0]);
	else if( 2 == num)
		printf("%d\n", p[0] + p[1]);
	else
		printf("%d\n", p[0] + p[1] + p[2]);
}