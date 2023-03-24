#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100 // ������������ ����� ����� � �������

// ����������� ����-��������� humen
typedef struct {
    char first_name[MAX_LEN];
    char last_name[MAX_LEN];
    int birth_year;
} humen;

// ������� ��� ��������� ��������� ���� humen �� ���� ��������
int compare_birth_year(const void *a, const void *b) {
    const humen *h1 = (const humen*) a;
    const humen *h2 = (const humen*) b;

    return (h1->birth_year - h2->birth_year);
}

int main() {
    humen arr1[4], arr2[4];
    int i;

    // ���� ��������� ������� arr1
    for (i = 0; i < 4; i++) {
        printf("������� ���, ������� � ��� �������� %d-�� ��������: ", i+1);
        scanf("%s %s %d", arr1[i].first_name, arr1[i].last_name, &arr1[i].birth_year);
    }

    // ����������� ��������� ������� arr1 � arr2
    memcpy(arr2, arr1, sizeof(humen) * 4);

    // ���������� ��������� ������� arr2 �� ���� ��������
    qsort(arr2, 4, sizeof(humen), compare_birth_year);

    // ����� ��������� ������� arr2
    printf("\n�������� ������� arr2, ��������������� �� ���� ��������:\n");
    for (i = 0; i < 4; i++) {
        printf("%s %s %d\n", arr2[i].first_name, arr2[i].last_name, arr2[i].birth_year);
    }

    return 0;
}


