#include <stdio.h>
#include <stdbool.h>
#include "reloj_RELOJ.h" // Incluir el archivo de cabecera generado
int main()
{
    // Variables de entrada y salida
    int hora = 12;
    int minuto = 0;
    int segundo = 0;
    int tiempo;

    // Simulación de interacción con el usuario
    while (true)
    {
        // Solicitar al usuario qué operación quiere realizar
        char opcion;
        printf("Hora actual: %d:%d:%d\n", hora, minuto, segundo);
        printf("¿Qué quiere cambiar? (h = Horas, m = Minutos, s = Segundos, e = Ejecutar,  x = Salir): ");

        scanf(" %c", &opcion);

        if (opcion == 'x')
        {
            break;
        }
        if (opcion == 'h')
        {
            printf("Introduce la nueva hora: ");
            scanf("%d", &hora);
        }
        if (opcion == 'm')
        {
            printf("Introduce el nuevo minuto: ");
            scanf("%d", &minuto);
        }
        if (opcion == 's')
        {
            printf("Introduce el nuevo segundo: ");
            scanf("%d", &segundo);
        }
        if (opcion == 'e')
        {
            // Llamar a la función principal de RELOJ
            reloj_RELOJ_step(hora, minuto, segundo, &tiempo);
            // Mostrar el estado del reloj
            printf("%d segundos han pasado desde las 12:00:00\n", tiempo);
        }
    }
    return 0;
}