#pragma hdrstop
#include <stdio.h>
#include <conio.h> // ���������� � "� ������ 2 contol.cpp"
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char s[80]; // ��������� ����������
	int i;
	if(fgets(s,80,stdin)) // fgets - ������ ������ �� ���������� ������ ������,� stdin ������������ ��� ���������� � �������.
	{
		for(i=0;s[i];i++) // ������������ ���� ��������
		{
			if(s[i]=='a') // �������� �������
			{
				s[i]='A'; // ���� ��������, �� � ������� �����
			}
			else
			{
				if(s[i]=='b') // ��������
				{
					s[i]='B'; // ����.....
				}
			}
		}
	}
	puts(s); // ����� s
	return 0;
}
