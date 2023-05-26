#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct Person {
    char name[50];
    char surname[50];
    int birthYear;
    char gender;
    float height;
};

int comparePersons(const void *a, const void *b) {
    const struct Person *personA = (const struct Person *)a;
    const struct Person *personB = (const struct Person *)b;

    // Проверка по году рождения
    if (personA->birthYear != personB->birthYear)
        return personA->birthYear - personB->birthYear;

    // Проверка по имени/фамилии
    int nameComparison = strcmp(personA->name, personB->name);
    if (nameComparison != 0)
        return nameComparison;

    // Проверка по полу
    if (personA->gender != personB->gender)
        return personA->gender - personB->gender;

    // Проверка по росту
    if (personA->height != personB->height)
        return personA->height - personB->height;

    // Если все поля равны, считаем записи равными
    return 0;
}

int main() {
    setlocale(LC_ALL, "");  // Установка локали для поддержки Unicode

    FILE *file = fopen("P.txt", "r");
    if (file == NULL) {
        printf("Ошибка открытия файла.\n");
        return 1;
    }

    int numPersons;
    fscanf(file, "%d", &numPersons);

    struct Person *persons = (struct Person *)malloc(numPersons * sizeof(struct Person));
	
	int i;
    for (i = 0; i < numPersons; i++) {
        fscanf(file, "%s %s %d %c %f",
               persons[i].name, persons[i].surname, &persons[i].birthYear,
               &persons[i].gender, &persons[i].height);
    }

    fclose(file);

    int numFields;
    printf("\nВведите количество полей для упорядочивания (1-4): ");
    scanf("%d", &numFields);

    int fieldIndices[4] = {0};  // Индексы полей для упорядочивания

    printf("\nУкажите индексы полей для упорядочивания (0-3):\n");
    for (i = 0; i < numFields; i++) {
        printf("Поле %d: ", i + 1);
        scanf("%d", &fieldIndices[i]);
    }

    qsort(persons, numPersons, sizeof(struct Person), comparePersons);

    printf("\nУпорядоченные записи:\n");
    for (i = 0; i < numPersons; i++) {
        printf("Запись %d:\n", i + 1);
        printf("Имя: %s\n", persons[i].name);
        printf("Фамилия: %s\n", persons[i].surname);
        printf("Год рождения: %d\n", persons[i].birthYear);
        printf("Пол: %c\n", persons[i].gender);
        printf("Рост: %.2f м\n", persons[i].height);
        printf("\n");
    }

    free(persons);
    return 0;
}


