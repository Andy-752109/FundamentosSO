/*Escribir un programa que cree un hijo. El hijo debe  escribir "Soy el hijo"
 diez veces. El padre debe escribir "Soy el padre" diez veces. Ambos procesos deberpan mostrar concurrentemente sus lie
 lineas en pantalla y entre cada linea que escriban debe haber una pausa de 
 1 segundo. E padre debe esperar a que termine el hijo y mostrar el mensaje "Mi proeso hijo
 ya ha terminado".*/
 
 // code
#include <stdio.h>
#include <unistd.h> //fork, sleep ()
#include <sys/wait.h> //wait

int main(){
    int pid = fork();

    if (pid < 0 ){ // Verifica si hubo un error al crear el proceso hijo
        // fork devuelve un valor negativo si hay un error al crear el proceso hijo
        printf("Se ejecuto erroneamente");
        return 1;
    } else if (pid == 0 ){ // Proceso hijo
        // fork devuelve 0 en el proceso hijo
        for(int i = 0; i < 10; i++){ // Bucle para imprimir "Soy el hijo" 10 veces
            printf("Soy el hijo\n");
            sleep(1); // Pausa de 1 segundo entre cada impresión
        }

    } else {// Proceso padre
        for ( int i = 0; i < 10; i++)
        {
            printf("Soy el padre\n");
            sleep(1);
        }
        wait(NULL); // El padre espera a que el hijo termine
        printf("Mi proceso hijo ya ha terminado"); // Mensaje final del padre
    }
}