#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct {
    char name[50];
    char surname[50];
    int birth_year;
} humen;

int compare_surname(const void* a, const void* b) {
    return strcmp(((humen*)a)->surname, ((humen*)b)->surname);
}

int main() {
    setlocale(LC_ALL, "Russian");

    humen people[4];
    humen sorted_people[4];

    printf("Введите данные о 4-ех людях:\n");

	int i;
    for (i = 0; i < 4; i++) {
        printf("Человек %d:\n", i+1);
        printf("Имя: ");
        scanf("%s", people[i].name);
        printf("Фамилия: ");
        scanf("%s", people[i].surname);
        printf("Год рождения: ");
        scanf("%d", &people[i].birth_year);
    }

    memcpy(sorted_people, people, sizeof(humen) * 4);

    qsort(sorted_people, 4, sizeof(humen), compare_surname);

    printf("\nОтсортированный массив:\n");

    for (i = 0; i < 4; i++) {
        printf("%s %s %d\n", sorted_people[i].name, sorted_people[i].surname, sorted_people[i].birth_year);
    }

    return 0;
}

