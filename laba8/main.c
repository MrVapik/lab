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

    // �������� �� ���� ��������
    if (personA->birthYear != personB->birthYear)
        return personA->birthYear - personB->birthYear;

    // �������� �� �����/�������
    int nameComparison = strcmp(personA->name, personB->name);
    if (nameComparison != 0)
        return nameComparison;

    // �������� �� ����
    if (personA->gender != personB->gender)
        return personA->gender - personB->gender;

    // �������� �� �����
    if (personA->height != personB->height)
        return personA->height - personB->height;

    // ���� ��� ���� �����, ������� ������ �������
    return 0;
}

int main() {
    setlocale(LC_ALL, "");  // ��������� ������ ��� ��������� Unicode

    FILE *file = fopen("P.txt", "r");
    if (file == NULL) {
        printf("������ �������� �����.\n");
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
    printf("\n������� ���������� ����� ��� �������������� (1-4): ");
    scanf("%d", &numFields);

    int fieldIndices[4] = {0};  // ������� ����� ��� ��������������

    printf("\n������� ������� ����� ��� �������������� (0-3):\n");
    for (i = 0; i < numFields; i++) {
        printf("���� %d: ", i + 1);
        scanf("%d", &fieldIndices[i]);
    }

    qsort(persons, numPersons, sizeof(struct Person), comparePersons);

    printf("\n������������� ������:\n");
    for (i = 0; i < numPersons; i++) {
        printf("������ %d:\n", i + 1);
        printf("���: %s\n", persons[i].name);
        printf("�������: %s\n", persons[i].surname);
        printf("��� ��������: %d\n", persons[i].birthYear);
        printf("���: %c\n", persons[i].gender);
        printf("����: %.2f �\n", persons[i].height);
        printf("\n");
    }

    free(persons);
    return 0;
}


