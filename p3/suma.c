/*
lv6 p3/suma.lus -node suma -cc -dir p3 &&
gcc -c p3/suma_suma.c -o p3/suma_suma.o &&
gcc -c p3/suma.c -o p3/suma.o &&
gcc p3/suma_suma.o p3/suma.o -o p3/programa_suma &&
p3/programa_suma
*/
#include <stdio.h>
#include "suma_suma.h" // Incluye el archivo de cabecera generado por Lustre
int main()
{
    int a, b, c;
    // Ejemplo de entrada
    printf("Introduce el valor de a: ");
    scanf("%d", &a);
    printf("Introduce el valor de b: ");
    scanf("%d", &b);
    // Llamar a la función Lustre
    // Pasa un puntero a ’c’ para almacenar el resultado
    suma_suma_step(a, b, &c);
    // Mostrar el resultado
    printf("La suma es: %d\n", c);
    return 0;
}