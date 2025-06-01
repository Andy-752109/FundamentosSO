#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
    int n;

    if(argc < 2){
        fprintf(stderr, "Uso: %s niveles \n", argv[0]);
        return 1;
    }

    n = atoi(argv[1]);

    printf("0\n");

    for(int i=1; i <= n; i++){
        pid_t pid = fork(); //

        if (pid < 0){
            perror("fork"); //
            exit(1);
        }
        printf("%d\n",i);
    }
    while(wait(NULL) > 0){

    }
    return 0;
}


