#include <stdio.h>

#define MAX_NUMBER(arr, count) \
    ({ \
        int max = arr[0]; \
        int i; \
        for (i = 1; i < count; i++) { \
            if (arr[i] > max) { \
                max = arr[i]; \
            } \
        } \
        max; \
    })

int main() {
    int count;
    printf("Enter the count of numbers: ");
    scanf("%d", &count);

    int numbers[count];
    printf("Enter the numbers separated by space: ");
    int i;
    for (i = 0; i < count; i++) {
        scanf("%d", &numbers[i]);
    }

    int maxNumber = MAX_NUMBER(numbers, count);
    printf("Maximum number: %d\n", maxNumber);

    return 0;
}

//макрос MAX_NUMBER, который принимает в качестве параметров массив чисел arr и их количество count. 
//Макрос выполняет цикл для поиска максимального числа в массиве и возвращает найденное максимальное число.
