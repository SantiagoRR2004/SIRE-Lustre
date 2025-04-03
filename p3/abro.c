/*
lv6 p3/abro.lus -node ABRO -cc -dir p3 &&
gcc -c p3/abro_ABRO.c -o p3/abro_ABRO.o &&
gcc -c p3/abro.c -o p3/abro.o &&
gcc p3/abro_ABRO.o p3/abro.o -o p3/programa_abro &&
p3/programa_abro
*/
#include <stdio.h>
#include <stdbool.h>
#include "abro_ABRO.h" // Incluir el archivo de cabecera generado
int main()
{
    // Variables de entrada y salida
    _boolean A = false;             // Señal A
    _boolean B = false;             // Señal B
    _boolean R = false;             // Reset
    _boolean O = false;             // Salida O
    abro_ABRO_ctx_type abro_ctx;    // Contexto del nodo ABRO
    abro_ABRO_ctx_reset(&abro_ctx); // Inicializar el contexto
    // Simulación de interacción con el usuario
    while (true)
    {
        A = false; // Reiniciar la señal A
        B = false; // Reiniciar la señal B
        R = false; // Reiniciar el reset
        // Solicitar al usuario qué señal desea enviar
        char opcion[3];
        printf("¿Qué señal desea enviar? (a = A, b = B, r = Reset, s = salir): ");

        // El único problema es que si es un enter vacío, no reacciona
        scanf("%3s", opcion);

        // Vaciar el buffer de entrada
        int c;
        while ((c = getchar()) != '\n' && c != EOF);  

        if (strchr(opcion, 'a') != NULL)
        { // Activar la señal A
            A = true;
        }
        if (strchr(opcion, 'b') != NULL)
        { // Activar la señal B
            B = true;
        }
        if (strchr(opcion, 'r') != NULL)
        { // Activar el reset
            R = true;
        }
        if (strchr(opcion, 's') != NULL)
        { // Salir del programa
            break;
        }
        // Llamar a la función principal de ABRO
        abro_ABRO_step(A, B, R, &O, &abro_ctx);
        // Mostrar el estado de la salida
        if (O)
        {
            printf("¡Salida O activada!\n");
        }
        else
        {
            printf("Salida O desactivada.\n");
        }
    }
    return 0;
}