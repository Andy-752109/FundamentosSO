// ejer4.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char comando[256];

    while (1) {

        printf("Ingresa un programa o 'exit' para salir: ");
        if (fgets(comando, sizeof(comando), stdin) == NULL) {

            perror("fgets");
            return 1;
        }

        //Quita el \n que agrega fgets
        size_t len = strlen(comando);
        if (len > 0 && comando[len - 1] == '\n') {
            comando[len - 1] = '\0';
        }

        if (strcmp(comando, "exit") == 0) {
            printf("Saliendo...\n");
            break;
        }

        if (strlen(comando) > 0) {
            int ret = system(comando);
            if (ret == -1) {
                perror("system");
                return 1;
            }
        }
    
    }

    return 0;
}
