#include <stdio.h>

int func(int n) {
	static int x = 0;
	if (n > 0) {
		x++;
		printf("%d\n", n);
		return func(n-1) + x;
	}
	return 0;
}

int main()
{
	printf("Result: %d\n", func(5));
}
