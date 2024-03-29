// pamit  videlenie
double** createMatrix(int n)
{
	int i;
    double** matrix = (double**)malloc(n * sizeof(double*));
    for (i = 0; i < n; i++)
    {
        matrix[i] = (double*)malloc(n * sizeof(double));
    }
    return matrix;
}

// pamit osbozdinei
void freeMatrix(double** matrix, int n)
{
	int i;
    for (i = 0; i < n; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

// vod matriz
void inputMatrix(double** matrix, int n)
{
	int i,j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%lf", &matrix[i][j]);
        }
    }
}

// vivod mtriz
void printMatrix(double** matrix, int n)
{
	int i,j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

// + matriz
double** addMatrix(double** matrix1, double** matrix2, int n)
{
	int i,j;
    double** result = createMatrix(n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return result;
}

// - mtriz
double** subtractMatrix(double** matrix1, double** matrix2, int n)
{
	int i,j;
    double** result = createMatrix(n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    return result;
}

// * mtriz
double** multiplyMatrix(double** matrix1, double** matrix2, int n)
{
	int i,j,k;
    double** result = createMatrix(n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            result[i][j] = 0;
            for (k = 0; k < n; k++)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return result;
}

// : mtriz
double** divisionMatrix(double** matrix1, double** matrix2, int n)
{
	int i,j,k;
    double** result = createMatrix(n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            result[i][j] = 0;
            for (k = 0; k < n; k++)
            {
                result[i][j] += matrix1[i][k] / matrix2[k][j];
            }
        }
    }
    return result;
}

// vibor oper
double** performOperation(double** matrix1, double** matrix2, int n, char operation)
{
    switch(operation)
    {
        case '+':
            return addMatrix(matrix1, matrix2, n);
        case '-':
            return subtractMatrix(matrix1, matrix2, n);
        case '*':
            return multiplyMatrix(matrix1, matrix2, n);
        case '/':
        	return divisionMatrix(matrix1, matrix2, n);
        default:           
        printf("ne verni znak oper\n");
        return NULL;
	}
}
