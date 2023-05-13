#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

double calculate_expression(char *expression);

int main() {
    char input[MAX_INPUT_LENGTH];
    printf("ved veraz:\n");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    double result = calculate_expression(input);
    printf("rezylt: %.2f\n", result);
    return 0;
}

double calculate_expression(char *expression) {
    char *token;
    double result = 0;
    char operator = '+';
    while ((token = strtok(expression, " ")) != NULL) {
        if (isdigit(token[0])) {
            double number = atof(token);
            switch (operator) {
                case '+':
                    result += number;
                    break;
                case '-':
                    result -= number;
                    break;
            }
        } else if (token[0] == '+') {
            operator = '+';
        } else if (token[0] == '-') {
            operator = '-';
        }
        expression = NULL;
    }
    return result;
}

//Программа сначала запрашивает у пользователя арифметическое выражение, затем вызывает функцию calculate_expression, которая разбивает выражение на токены (числа и операторы) с помощью функции strtok. 
//Далее происходит расчёт выражения, и функция возвращает результат.
