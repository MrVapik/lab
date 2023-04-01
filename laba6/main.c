#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100 

int main() {
    FILE *in_file, *out_file;
    char buffer[MAX_LEN];
    char *last_name, *first_name, *middle_name;
    int birth_year;


    in_file = fopen("input.txt", "r");
    out_file = fopen("output.txt", "w");


    if (in_file == NULL || out_file == NULL) {
        printf("?????? ???????? ?????\n");
        exit(1);
    }


    while (fgets(buffer, MAX_LEN, in_file)) {
        int num_tokens = 0;
        char *token = strtok(buffer, " ");
        while (token != NULL) {
            switch(num_tokens) {
                case 0:
                    last_name = token;
                    break;
                case 1:
                    first_name = token;
                    break;
                case 2:
                    middle_name = token;
                    break;
                case 3:
                    birth_year = atoi(token);
                    break;
                }
                token = strtok(NULL, " ");
                num_tokens++;
            }

            if (num_tokens == 1) {
                first_name = last_name;
                last_name = "";
                middle_name = "";
                birth_year = atoi(first_name);
            } else if (num_tokens == 2) {
                middle_name = "";
                birth_year = atoi(first_name);
                first_name = last_name;
                last_name = "";
            } else if (num_tokens == 3) {
                birth_year = atoi(middle_name);
                middle_name = "";
            }

        if (birth_year > 1980) {
            fprintf(out_file, "%s %s %s %d\n", last_name, first_name, middle_name, birth_year);
        }
    }


    fclose(in_file);
    fclose(out_file);

    return 0;
}
