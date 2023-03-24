#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100 // ������������ ����� ������ � �����

int main() {
    FILE *in_file, *out_file;
    char buffer[MAX_LEN];
    char *last_name, *first_name, *middle_name;
    int birth_year;

    // �������� ������ ��� ������ � ������
    in_file = fopen("input.txt", "r");
    out_file = fopen("output.txt", "w");

    // ��������� ������ �������� ������
    if (in_file == NULL || out_file == NULL) {
        printf("������ �������� ������\n");
        exit(1);
    }

    // ����� �����, ����������� � ���������� ������� 1980 ����
    while (fgets(buffer, MAX_LEN, in_file)) {
        // ���������� ������ �� ����
        last_name = strtok(buffer, " ");
        first_name = strtok(NULL, " ");
        middle_name = strtok(NULL, " ");
        birth_year = atoi(strtok(NULL, " "));

        // ������ ������ � �������� ����, ���� ��� �������� ������� 1980
        if (birth_year > 1980) {
            fprintf(out_file, "%s %s %s %d\n", last_name, first_name, middle_name, birth_year);
        }
    }

    // �������� ������
    fclose(in_file);
    fclose(out_file);

    return 0;
}

