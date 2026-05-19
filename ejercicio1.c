#include <stdio.h>

// calcula base^exp
int potencia(int base, int exp) {
    int resultado = 1;
    while (exp > 0) {
        resultado = resultado * base;
        exp = exp - 1;
    }
    return resultado;
}

// retorna 1 si n es par, 0 si impar
int es_par(int n) {
    if (n % 2 == 0)
        return 1;
    return 0;
}

int main(void) {
    int base, exp, res;

    do {
        printf("Ingrese la base (no puede ser 0): ");
        scanf("%d", &base);
        if (base == 0)
            printf("Base invalida, intente de nuevo.\n");
    } while (base == 0);

    do {
        printf("Ingrese el exponente (debe ser >= 0): ");
        scanf("%d", &exp);
        if (exp < 0)
            printf("Exponente invalido, intente de nuevo.\n");
    } while (exp < 0);

    res = potencia(base, exp);
    printf("%d^%d = %d\n", base, exp, res);

    if (es_par(res))
        printf("El resultado es par.\n");
    else
        printf("El resultado es impar.\n");

    return 0;
}
