# Laboratorio #3 — IE-0117 Programación Bajo Plataformas Abiertas

**Estudiante:** Daniel Castro Ramírez  
**Carné:** C21931

---

## Repositorio de GitHub

[https://github.com/dcastro281003/Laboratorio-3](https://github.com/dcastro281003/Laboratorio-3)

---

## Ejercicio 1 — Potencia entera

### Compilación

```bash
gcc -Wall ejercicio1.c -o ej1
```

El código compila sin errores ni advertencias.

### Error encontrado y corrección

En el código original, la línea dentro del `while` era:

```c
int exp = exp - 1;
```

El problema es que al poner `int` se está creando una variable nueva llamada `exp` dentro del ciclo, en vez de modificar la que ya existe como parámetro. Eso hace que el parámetro nunca cambie y el ciclo no termine. La corrección es quitar el `int`:

```c
exp = exp - 1;
```

### Muestras de ejecución

**2^8**
```
Ingrese la base (no puede ser 0): 2
Ingrese el exponente (debe ser >= 0): 8
2^8 = 256
El resultado es par.
```

**3^4**
```
Ingrese la base (no puede ser 0): 3
Ingrese el exponente (debe ser >= 0): 4
3^4 = 81
El resultado es impar.
```

**Validación de entradas inválidas**
```
Ingrese la base (no puede ser 0): 0
Base invalida, intente de nuevo.
Ingrese la base (no puede ser 0): 2
Ingrese el exponente (debe ser >= 0): -3
Exponente invalido, intente de nuevo.
Ingrese el exponente (debe ser >= 0): 5
2^5 = 32
El resultado es par.
```

---

## Ejercicio 2 — Matrices binarias

### Compilación

```bash
gcc -Wall ejercicio2.c -o ej2
```

El código compila sin errores ni advertencias. Para probar con otros tamaños:

```bash
gcc -Wall -DSIZE=2 ejercicio2.c -o ej2_s2
gcc -Wall -DSIZE=6 ejercicio2.c -o ej2_s6
```

### Pseudocódigo de dos funciones

**es_identidad**
```
FUNCIÓN es_identidad(m):
    PARA cada fila i:
        PARA cada columna j:
            SI i == j y m[i][j] != 1: retornar 0
            SI i != j y m[i][j] != 0: retornar 0
    retornar 1
```

**tiene_fila_completa**
```
FUNCIÓN tiene_fila_completa(m):
    PARA cada fila i:
        SI contar_unos_fila(m, i) == SIZE:
            retornar 1
    retornar 0
```

### Muestras de ejecución

**SIZE = 2**
```
Matriz ingresada:
1 0
0 1
Es matriz identidad: si
Tiene fila completa de unos: no
Tiene columna completa de unos: no

Matriz aleatoria:
1 1
0 0
Es matriz identidad: no
Tiene fila completa de unos: si
Tiene columna completa de unos: no
```

**SIZE = 4**
```
Matriz ingresada:
1 0 0 0
0 1 0 0
0 0 1 0
0 0 0 1
Es matriz identidad: si
Tiene fila completa de unos: no
Tiene columna completa de unos: no

Matriz aleatoria:
1 1 1 1
0 1 0 0
1 0 1 0
0 0 1 1
Es matriz identidad: no
Tiene fila completa de unos: si
Tiene columna completa de unos: no
```

**SIZE = 6**
```
Matriz ingresada:
1 0 0 0 0 0
0 1 0 0 0 0
0 0 1 0 0 0
0 0 0 1 0 0
0 0 0 0 1 0
0 0 0 0 0 1
Es matriz identidad: si
Tiene fila completa de unos: no
Tiene columna completa de unos: no

Matriz aleatoria:
0 1 1 0 0 1
1 1 1 1 1 1
0 0 0 1 0 0
1 0 1 0 1 1
0 0 1 1 1 0
0 1 0 1 1 0
Es matriz identidad: no
Tiene fila completa de unos: si
Tiene columna completa de unos: no
```

### Discusión

La matriz identidad tiene 1s solo en la diagonal y 0s en el resto. Las matrices aleatorias se generan con `rand() % 2` y cambian en cada ejecución porque se usa `srand(time(NULL))` para la semilla. El programa funciona con cualquier valor de `SIZE` porque la matriz identidad se construye con un ciclo en vez de estar escrita a mano.

---

## Ejercicio 3 — Sensores

### Compilación

```bash
gcc -Wall ejercicio3.c -o ej3
```

El código compila sin errores ni advertencias.

### Umbrales de clasificación

| Rango          | Estado |
|----------------|--------|
| 40.0 a 60.0    | NORMAL |
| 20.0 a 40.0 o 60.0 a 80.0 (sin incluir extremos) | ALERTA |
| Menor a 20.0 o mayor a 80.0 | FALLO |

### Muestra de ejecución

```
Sensor 1 - ID: 1  Sensor 1 - Valor: 50.0
Sensor 2 - ID: 2  Sensor 2 - Valor: 35.5
...

ID     | Valor  | Estado
-------|--------|--------
1      | 50.00  | NORMAL
2      | 35.50  | ALERTA
3      | 72.00  | ALERTA
4      | 15.00  | FALLO
5      | 45.00  | NORMAL
6      | 88.00  | FALLO
7      | 60.00  | NORMAL
8      | 25.00  | ALERTA
9      | 40.00  | NORMAL
10     | 5.00   | FALLO

NORMAL: 4
ALERTA: 3
FALLO:  3

Lectura extrema: ID=10, Valor=5.00
```

### Discusión

La función `lectura_extrema` busca cuál valor está más lejos de 50.0, que es el centro del rango normal. En este caso el sensor 10 con valor 5.0 está a 45 unidades del centro, que es la distancia mayor. La función `contar_estado` recorre el arreglo y cuenta cuántas lecturas tienen cada estado.
