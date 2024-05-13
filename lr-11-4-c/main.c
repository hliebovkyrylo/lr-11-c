#include <stdio.h>
#include <string.h>
#include <windows.h>

int main(int argc, char* argv[]) {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    if (argc != 3) {
        printf("Використання програми: <рядок S> <рядок Q>\n", argv[0]);
        return 1;
    }

    char* S = argv[1];
    char* Q = argv[2];

    int lenS = strlen(S);
    int lenQ = strlen(Q);

    if (lenQ > lenS) {
        printf("Рядок Q не міститься в рядку S.\n");
        return 0;
    }

    char* found = strstr(S, Q);
    if (found == NULL) {
        printf("Рядок Q не міститься в рядку S.\n");
    }
    else {
        int position = found - S;
        if (position == 0) {
            printf("Рядок Q знаходиться на початку рядка S.\n");
        }
        else if (position == lenS - lenQ) {
            printf("Рядок Q знаходиться в кінці рядка S.\n");
        }
        else {
            printf("Рядок Q знаходиться в середині рядка S.\n");
        }
    }

    return 0;
}
