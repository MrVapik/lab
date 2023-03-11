#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int a, i, j, k;
    double x1=0, x2=0;
	scanf("%d", &a);
	double x[a][a], y[a][a];
	
	for (i = 0; i<a; i++)
	{
    	for (j = 0; j<a; j++)
		{
    		scanf("%lf", &x[i][j]);
    		if (i==j)
    		{
    			x1=x1+x[i][j];
			}
			if(a==i+j+1)
			{
    			x2=x2+x[i][j];
			}
    	}
	}

	for (i=0; i<a; i++)
	
	{
	    for (j=0; j<a; j++)
    	    printf("%lf ", x[i][j]);
    	printf("\n");
	}
	printf("%lf, %lf", x1, x2);
	for(i = 0; i<a; i++)
	{
    	for(j = 0; j<a; j++)
    	{
   		    y[i][j]=0;
 		    for(k=0; k<a; k++)
    	    y[i][j] += x[i][k] * x[k][j];
    	}
	}

	for (i=0; i<a; i++)
	{
	    for (j=0; j<a; j++)
    	    printf("%lf ", y[i][j]);
    	printf("\n");
	}
}
