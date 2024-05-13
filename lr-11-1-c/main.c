#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int M, N;

    do {
        printf("������ ������� ��������: ");
        if (scanf_s("%d", &N) != 1) {
            printf("���������� ��������! ��������� �� ���.\n");
            while (getchar() != '\n');
        }
    } while (N <= 0);

    do {
        printf("������ ������� �����: ");
        if (scanf_s("%d", &M) != 1) {
            printf("���������� ��������! ��������� �� ���.\n");
            while (getchar() != '\n');
        }
    } while (M <= 0);

    int** A = (int**)malloc(M * sizeof(int*));
    if (A == NULL) {
        printf("������� �������� ���'��!\n");
        return 1;
    }

    for (int i = 0; i < M; i++) {
        A[i] = (int*)malloc(N * sizeof(int));
        if (A[i] == NULL) {
            printf("������� �������� ���'��!\n");
            for (int j = 0; j < i; j++) {
                free(A[j]);
            }
            free(A);
            return 1;
        }
    }

    int* B = (int*)malloc(M * sizeof(int));
    if (B == NULL) {
        printf("������� �������� ���'��!\n");
        for (int i = 0; i < M; i++) {
            free(A[i]);
        }
        free(A);
        return 1;
    }

    printf("������ �������� �������:\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("A[%d][%d] = ", i, j);
            if (scanf_s("%d", &A[i][j]) != 1) {
                printf("���������� ��������! ��������� �� ���.\n");
                while (getchar() != '\n');
                j--;
            }
        }
    }

    for (int i = 0; i < M; i++) {
        int min = INT_MAX;
        for (int j = 0; j < N; j++) {
            if (A[i][j] < min) {
                min = A[i][j];
            }
        }
        B[i] = min;
    }

    printf("̳������ �������� � ������: ");
    for (int i = 0; i < M; i++) {
        printf("%d ", B[i]);
    }
    printf("\n");

    for (int i = 0; i < M; i++) {
        free(A[i]);
    }
    free(A);
    free(B);

    return 0;
}