#include <stdio.h>

/* using pascal triangle */
/* i.e. nCr can be obtained by adding nCr-1 and nCr*/
float combination(int n, int r) {
	if (r == 0 || n ==r)
		return 1.0;
	return combination(n-1, r-1) + combination(n-1, r);
}

int main(int argc, char *argv[])
{
	printf("%f\n", combination(4,3));
}
