#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	double massiv[3][3];
	int i,j;
	for (i = 0; i<3;i++)
	{
		for(j=0; j<3;j++)
		{
			scanf("%d", &massiv[i][j]);
		}
	}
	double kok = massiv[0][0] + massiv[2][2] + massiv[1][1];
	double fof = massiv[0][2] + massiv[2][0] + massiv[1][1];
	printf("Sum main = %d \n", kok);
	printf("Sum side = %d \n", fof);
	int d,s,m[2][2];
	for (d = 0; d<2;d++)
	{
		for(s = 0; s<2; s++)
		{
			scanf("%d", &m[d][s]);
		}
	}
	printf("|%d %d|\n", m[0][0]*m[0][0] + m[0][1]*m[1][0], m[0][0]*m[0][1] + m[0][1]*m[1][1]);
	printf("|%d %d|", m[0][0]*m[1][0] + m[1][1]*m[1][0], m[1][0]*m[0][1] + m[1][1]*m[1][1]);
	return 0;
}
