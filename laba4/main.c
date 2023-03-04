#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	int i,j; 
	int n,s,k,m=1; 
	printf("N: ");
	scanf("%d",&n);
	int a[n][n];
	for(i=0; i< n; i++)
	{
		printf("Line %d: ",i+1);
		for(j=0; j< n; j++)scanf("%d",&a[i][j]);
	}
	k=0;
	for(j=0; j< n; j++)k+=a[j][j];
	s=0;
	for(j=0; j< n; j++)s+=a[j][n-j-1];
	if(s!=k)m=0;
	for(j=0; j< n; j++)
	{
		s=0;
		for(i=0; i< n; i++)s+=a[i][j];
		if(s!=k)m=0;
	}
	for(j=0; j< n; j++)
	{
		s=0;
		for(i=0; i< n; i++)s+=a[j][i];
		if(s!=k)m=0;
	}
	printf("%s\n",m?"true":"false");
	return 0;
}
