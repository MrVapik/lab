#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100 // Максимальная длина строки в файле

int main() {
    FILE *in_file, *out_file;
    char buffer[MAX_LEN];
    char *last_name, *first_name, *middle_name;
    int birth_year;

    // Открытие файлов для чтения и записи
    in_file = fopen("input.txt", "r");
    out_file = fopen("output.txt", "w");

    // Обработка ошибок открытия файлов
    if (in_file == NULL || out_file == NULL) {
        printf("Ошибка открытия файлов\n");
        exit(1);
    }

    // Поиск строк, относящихся к родившимся позднее 1980 года
    while (fgets(buffer, MAX_LEN, in_file)) {
        // Разделение строки на поля
        last_name = strtok(buffer, " ");
        first_name = strtok(NULL, " ");
        middle_name = strtok(NULL, " ");
        birth_year = atoi(strtok(NULL, " "));

        // Запись строки в выходной файл, если год рождения позднее 1980
        if (birth_year > 1980) {
            fprintf(out_file, "%s %s %s %d\n", last_name, first_name, middle_name, birth_year);
        }
    }

    // Закрытие файлов
    fclose(in_file);
    fclose(out_file);

    return 0;
}

