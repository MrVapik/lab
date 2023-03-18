#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include "f.h"

int main()
{
int n;
printf("n: ");
scanf("%d", &n);
double** matrix1 = createMatrix(n);
double** matrix2 = createMatrix(n);

printf("1m: ");
inputMatrix(matrix1, n);

printf("2m: ");
inputMatrix(matrix2, n);

char operation;
printf("(+, -, *, /): ");
scanf(" %c", &operation);

double** result = performOperation(matrix1, matrix2, n, operation);
if (result != NULL)
{
    printf("resultat:\n");
    printMatrix(result, n);
    freeMatrix(result, n);
}

freeMatrix(matrix1, n);
freeMatrix(matrix2, n);

return 0;
}
