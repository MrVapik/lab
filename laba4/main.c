#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <locale.h>
#include "zxc.h"

int main()
{
	double a, b, c, u, i;
	printf("a b c: ");
	scanf("%lf%lf%lf", &a, &b, &c);
	if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || b + c <= a || c + a <= b)
	printf("The triangle does not exist");
	else
	{
		u = perimetr(a, b, c);
		i = ploshchadj(a, b, c);
		printf("perimetr %g\n", u);
		printf("ploshchad %g\n", i);
	}
	return 0;
}
