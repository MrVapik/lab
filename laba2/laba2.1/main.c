#pragma hdrstop
#include <stdio.h>
#include <conio.h> // Библиотеки с "к лекции 2 contol.cpp"
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char s[80]; // Объявляем переменные
	int i;
	if(fgets(s,80,stdin)) // fgets - чтение строки из указанного потока данных,а stdin используется для считывания с консоли.
	{
		for(i=0;s[i];i++) // классический цикл перебора
		{
			if(s[i]=='a') // проверка символа
			{
				s[i]='A'; // Если подходит, то с большой буквы
			}
			else
			{
				if(s[i]=='b') // проверка
				{
					s[i]='B'; // если.....
				}
			}
		}
	}
	puts(s); // вывод s
	return 0;
}
