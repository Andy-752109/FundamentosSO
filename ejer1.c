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

    if (pid < 0 ){
        printf("Se ejecuto erroneamente");
        return 1;
    } else if (pid == 0 ){
        for(int i = 0; i < 10; i++){
            printf("Soy el hijo\n");
            sleep(1);
        }

    } else {
        for ( int i = 0; i < 10; i++)
        {
            printf("Soy el padre\n");
            sleep(1);
        }
        wait(NULL);
        printf("Mi proceso hijo ya ha terminado");
    }
}