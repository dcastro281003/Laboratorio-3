#include <stdio.h>
#include <math.h>

#define MAX_SENSORES 10

typedef enum { NORMAL, ALERTA, FALLO } EstadoSensor;

typedef struct {
    int id;
    float valor;
    EstadoSensor estado;
} Lectura;

EstadoSensor clasificar(float valor);
int contar_estado(Lectura s[], int n, EstadoSensor e);
int lectura_extrema(Lectura s[], int n);

EstadoSensor clasificar(float valor) {
    if (valor >= 40.0 && valor <= 60.0)
        return NORMAL;
    else if ((valor > 20.0 && valor < 40.0) || (valor > 60.0 && valor < 80.0))
        return ALERTA;
    else
        return FALLO;
}

int contar_estado(Lectura s[], int n, EstadoSensor e) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (s[i].estado == e)
            count++;
    }
    return count;
}

// retorna indice de la lectura mas alejada de 50.0
int lectura_extrema(Lectura s[], int n) {
    int idx = 0;
    float max = fabsf(s[0].valor - 50.0);
    for (int i = 1; i < n; i++) {
        float d = fabsf(s[i].valor - 50.0);
        if (d > max) {
            max = d;
            idx = i;
        }
    }
    return idx;
}

int main(void) {
    Lectura s[MAX_SENSORES];

    for (int i = 0; i < MAX_SENSORES; i++) {
        printf("Sensor %d - ID: ", i+1);
        scanf("%d", &s[i].id);
        printf("Sensor %d - Valor: ", i+1);
        scanf("%f", &s[i].valor);
        s[i].estado = clasificar(s[i].valor);
    }

    printf("\nID     | Valor  | Estado\n");
    printf("-------|--------|--------\n");
    for (int i = 0; i < MAX_SENSORES; i++) {
        char *est;
        if (s[i].estado == NORMAL) est = "NORMAL";
        else if (s[i].estado == ALERTA) est = "ALERTA";
        else est = "FALLO";
        printf("%-6d | %-6.2f | %s\n", s[i].id, s[i].valor, est);
    }

    printf("\nNORMAL: %d\n", contar_estado(s, MAX_SENSORES, NORMAL));
    printf("ALERTA: %d\n", contar_estado(s, MAX_SENSORES, ALERTA));
    printf("FALLO:  %d\n", contar_estado(s, MAX_SENSORES, FALLO));

    int idx = lectura_extrema(s, MAX_SENSORES);
    printf("\nLectura extrema: ID=%d, Valor=%.2f\n", s[idx].id, s[idx].valor);

    return 0;
}
