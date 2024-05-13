#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define NUM_SURNAMES 10
#define MAX_LENGTH 50

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    char** surnames;
    char** pointers;

    surnames = (char**)malloc(NUM_SURNAMES * sizeof(char*));
    pointers = (char**)malloc(NUM_SURNAMES * sizeof(char*));

    if (surnames == NULL || pointers == NULL) {
        printf("Помилка виділення пам'яті.\n");
        return 1;
    }

    printf("Введіть %d прізвищ:\n", NUM_SURNAMES);
    for (int i = 0; i < NUM_SURNAMES; i++) {
        surnames[i] = (char*)malloc(MAX_LENGTH * sizeof(char));
        if (surnames[i] == NULL) {
            printf("Помилка виділення пам'яті.\n");
            return 1;
        }
        printf("Прізвище %d: ", i + 1);
        fgets(surnames[i], MAX_LENGTH, stdin);
        surnames[i][strcspn(surnames[i], "\n")] = '\0';
        pointers[i] = surnames[i];
    }

    for (int i = 0; i < NUM_SURNAMES - 1; i++) {
        for (int j = i + 1; j < NUM_SURNAMES; j++) {
            if (strcmp(pointers[i], pointers[j]) > 0) {
                char* temp = pointers[i];
                pointers[i] = pointers[j];
                pointers[j] = temp;
            }
        }
    }

    printf("\nВідсортовані прізвища:\n");

    for (int i = 0; i < NUM_SURNAMES; i++) {
        printf("%s\n", pointers[i]);
    }

    for (int i = 0; i < NUM_SURNAMES; i++) {
        free(surnames[i]);
    }

    free(surnames);
    free(pointers);

    return 0;
}
