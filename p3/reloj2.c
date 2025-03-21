#include <stdio.h>
#include <stdbool.h>
#include "reloj_RELOJ.h"

int main() {
    // Variables de entrada y salida
    _boolean hora_signal = false;    
    _boolean minuto_signal = false;  
    _boolean segundo_signal = false; 
    int nueva_hora = 12, nuevo_minuto = 0, nuevo_segundo = 0;
    int tiempo = 0;
    char opcion[3];         
    reloj_RELOJ_ctx_type reloj_ctx; 
    reloj_RELOJ_ctx_reset(&reloj_ctx);

    while (true) {
        printf("Hora actual: %d:%d:%d\n", nueva_hora, nuevo_minuto, nuevo_segundo);
        printf("Segundos desde el mediodía: %d\n", tiempo);
        printf("Seleccione una opción:\n");
        printf("h = Cambiar la hora\n");
        printf("m = Cambiar el minuto\n");
        printf("s = Cambiar el segundo\n");
        printf("q = Salir\n\n");
        
        scanf("%3s", opcion);
        // Vaciar el buffer de entrada
        int c;
        while ((c = getchar()) != '\n' && c != EOF);  

        if (strchr(opcion, 'h') != NULL)
        { // Activar hora_signal
            printf("Introduce la nueva hora: ");
            scanf("%d", &nueva_hora);
            hora_signal = true;
            nueva_hora = nueva_hora % 24;
        }
        if (strchr(opcion, 'm') != NULL)
        { // Activar minuto_signal
            printf("Introduce el nuevo minuto: ");
            scanf("%d", &nuevo_minuto);
            minuto_signal = true;
            nuevo_minuto = nuevo_minuto % 60;
        }
        if (strchr(opcion, 's') != NULL)
        { // Activar segundo_signal
            printf("Introduce el nuevo segundo: ");
            scanf("%d", &nuevo_segundo);
            segundo_signal = true;
            nuevo_segundo = nuevo_segundo % 60;
        }
        if (strchr(opcion, 'q') != NULL)
        { // Salir del programa
            break;
        }
        reloj_RELOJ_step(hora_signal, minuto_signal, segundo_signal,
        nueva_hora, nuevo_minuto, nuevo_segundo,
        &tiempo, &reloj_ctx);
        hora_signal = minuto_signal = segundo_signal = false;
    }
    return 0;
}