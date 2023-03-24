#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100 // Максимальная длина имени и фамилии

// Определение типа-структуры humen
typedef struct {
    char first_name[MAX_LEN];
    char last_name[MAX_LEN];
    int birth_year;
} humen;

// Функция для сравнения элементов типа humen по году рождения
int compare_birth_year(const void *a, const void *b) {
    const humen *h1 = (const humen*) a;
    const humen *h2 = (const humen*) b;

    return (h1->birth_year - h2->birth_year);
}

int main() {
    humen arr1[4], arr2[4];
    int i;

    // Ввод элементов массива arr1
    for (i = 0; i < 4; i++) {
        printf("Введите имя, фамилию и год рождения %d-го человека: ", i+1);
        scanf("%s %s %d", arr1[i].first_name, arr1[i].last_name, &arr1[i].birth_year);
    }

    // Копирование элементов массива arr1 в arr2
    memcpy(arr2, arr1, sizeof(humen) * 4);

    // Сортировка элементов массива arr2 по году рождения
    qsort(arr2, 4, sizeof(humen), compare_birth_year);

    // Вывод элементов массива arr2
    printf("\nЭлементы массива arr2, отсортированные по году рождения:\n");
    for (i = 0; i < 4; i++) {
        printf("%s %s %d\n", arr2[i].first_name, arr2[i].last_name, arr2[i].birth_year);
    }

    return 0;
}


