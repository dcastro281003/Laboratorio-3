#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef SIZE
#define SIZE 4
#endif

int contar_unos_fila(int m[][SIZE], int fila);
int contar_unos_columna(int m[][SIZE], int col);
int es_identidad(int m[][SIZE]);
int tiene_fila_completa(int m[][SIZE]);
int tiene_columna_completa(int m[][SIZE]);

int contar_unos_fila(int m[][SIZE], int fila) {
    int c = 0;
    for (int j = 0; j < SIZE; j++) {
        if (m[fila][j] == 1) c++;
    }
    return c;
}

int contar_unos_columna(int m[][SIZE], int col) {
    int c = 0;
    for (int i = 0; i < SIZE; i++) {
        if (m[i][col] == 1) c++;
    }
    return c;
}

// retorna 1 si la matriz es identidad
int es_identidad(int m[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i == j && m[i][j] != 1) return 0;
            if (i != j && m[i][j] != 0) return 0;
        }
    }
    return 1;
}

int tiene_fila_completa(int m[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        if (contar_unos_fila(m, i) == SIZE)
            return 1;
    }
    return 0;
}

int tiene_columna_completa(int m[][SIZE]) {
    for (int j = 0; j < SIZE; j++) {
        if (contar_unos_columna(m, j) == SIZE)
            return 1;
    }
    return 0;
}

void imprimir_resultados(int m[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++)
            printf("%d ", m[i][j]);
        printf("\n");
    }
    printf("Es matriz identidad: %s\n", es_identidad(m) ? "si" : "no");
    printf("Tiene fila completa de unos: %s\n", tiene_fila_completa(m) ? "si" : "no");
    printf("Tiene columna completa de unos: %s\n", tiene_columna_completa(m) ? "si" : "no");
}

int main(void) {
    int m[SIZE][SIZE];
    int r[SIZE][SIZE];

    // llenar identidad
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            m[i][j] = (i == j) ? 1 : 0;

    srand((unsigned int)time(NULL));
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            r[i][j] = rand() % 2;

    printf("Matriz ingresada:\n");
    imprimir_resultados(m);

    printf("\nMatriz aleatoria:\n");
    imprimir_resultados(r);

    return 0;
}
