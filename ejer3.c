/*
*Desarrolla un programa que reciba como argumento desde la línea de comandos un valor de entrada n 
cuyo significado sera un número de procesos a crear, de manera que cuando ejecutes tu programa este 
será el proceso padre que creará solamente n procesos hijos a un nivel, cada proceso hijo mostrará su número 
que será de 1 hasta n. El proceso padre deberá esperar a que  todos los hijos terminen para al finalizar mostrar 
en pantalla el mensaje "Fin". Por ejemplo:

$ ./programa 5
Proceso hijo 1
Proceso hijo 2
Proceso hijo 3
Proceso hijo 4
Proceso hijo 5
Fin
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main (int argc, char *argv[]){
   
    int n;
   if (argc != 2) { // Verifica que se haya pasado un argumento (2 porque se espera que se ejecute: './ejer3 numero_de_procesos') siendo 2 argumentos
        fprintf(stderr, "Uso: %s numero_de_procesos\n", argv[0]); 
        //fprintf = función para escrbir texto formateado.
        //stderr = flujo de salida estándar para mensajes de error.
        return 1;
    }
    
    n = atoi(argv[1]); // Convierte el argumento de la línea de comandos a un entero
    // atoi = función que convierte una cadena de caracteres a un entero.

    if (n <= 0) { // Verifica que el número de procesos sea mayor que 0
        fprintf(stderr, "El numero de procesos debe ser mayor que 0\n");
        return 1;
    }

    // Crea n procesos hijos
    for (int i = 0; i < n; i++){ 
        int pid = fork(); 
        if (pid < 0){
            printf("Error al crear el proceso hijo\n");
            return 1;
        } else if (pid == 0)   // Proceso hijo
        {
            printf("Proceso hijo %d\n", i + 1); // Imprime el número del proceso hijo (i + 1 para que empiece desde 1)
            return 0; // Termina el proceso hijo
        }
    }
    for (int i = 0; i < n; i++) {
        wait(NULL); // El padre espera a que todos los hijos terminen
    }
    printf("Fin\n"); // Mensaje final del padre
    return 0;
}