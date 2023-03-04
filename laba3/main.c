#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	char s[80];
	int i;
	if(fgets(s,80,stdin))
	{
		for(i=0;s[i];i++)
		{
			if(s[i]=='a')
			{
				s[i]='A';
			}
			else
			{
				if(s[i]=='b')
				{
					s[i]='B';
				}
				else
				{
					if(s[i]=='!')
					{
						s[i]='?';
					}
				}
			}
		}
	}
	puts(s);
	return 0;
}
