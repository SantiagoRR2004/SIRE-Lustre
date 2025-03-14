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
        // Solicitar al usuario qué señal desea enviar
        char opcion;
        printf("¿Qué señal desea enviar? (a = A, b = B, r = Reset, s = salir): ");
        scanf(" %c", &opcion);
        if (opcion == "a")
        { // Activar la señal A
            A = true;
            B = false; // Reiniciar la señal B
            R = false; // Reiniciar el reset
        }
        else if (opcion == "b")
        { // Activar la señal B
            B = true;
            A = false; // Reiniciar la señal A
            R = false; // Reiniciar el reset
        }
        else if (opcion == "r")
        { // Activar el reset
            R = true;
            A = false; // Reiniciar la señal A
            B = false; // Reiniciar la señal B
        }
        else if (opcion == "s")
        { // Salir del programa
            break;
        }
        else
        {
            printf("Opción no válida.\n");
            continue;
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