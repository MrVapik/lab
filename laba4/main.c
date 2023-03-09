#include <stdio.h>
#include <math.h>

int main()
{
	double a, b, c;
	printf("a b c: ");
	scanf("%lf%lf%lf", &a, &b, &c);
	if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || b + c <= a || c + a <= b)
	printf("The triangle does not exist");
	else
	{
		perimetr(a, b, c);
		ploshchadj(a, b, c);
	}
}
void perimetr(double x, double y, double z)
{
	printf("perimetr %g\n", x + y + z);
}
void ploshchadj(double x, double y, double z)
{
	double p=(x+y+z)/2;
	printf("ploshchad %g\n", sqrt(p * (p - x) * (p - y) * (p - z)));
}
