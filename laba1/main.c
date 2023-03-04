#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	int a,b,c,d;
	double x1, x2;
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	d = b*b - 4*a*c;
	printf("d = %d \n", d);
	if (d > 0)
	{
		x1 = (-b + sqrt(d)) / (2*a);
		x2 = (-b - sqrt(d)) / (2*a);
		printf("x1 = %lf, x2=%lf",x1,x2);
	}
	if	(d == 0)
	{
		x1 = (-b) / (2*a);
		printf("x1 = %lf", x1, x2);
	}
	if (d < 0)
	{
		printf("d < 0, no x");
	}
	return 0;
}
