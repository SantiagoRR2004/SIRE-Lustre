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