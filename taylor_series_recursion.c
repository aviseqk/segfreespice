#include <stdio.h>

static float exp;
static float fact;

float taylor(int x, int n) {
	if (n == 0) {
		exp = 1.0;
		fact = 1.0;
		return 1.0;
	}
	float val =  taylor(x, n-1);
	fact = fact * n;
	exp = exp * x;
	return val + (exp/fact);
}

float taylor_horner(int x, int n) {
    static float s;
    if (n ==0)
        return s;
    s = 1 + x*s/n;
    return taylor_horner(x, n-1);
}

int main()
{
    printf("%f\n", taylor_horner(2,10));
	printf("%f\n", taylor(2,4));
}
