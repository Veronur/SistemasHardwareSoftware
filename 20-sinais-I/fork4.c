#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

void func1() {
    while (1) {
        printf("loop infinito! meu pid: %d\n", getpid());
        sleep(2);
    }
}


int main() {
    pid_t f1, f2, f3;
    int status;
    printf("pai: pid %d ppid %d\n", getpid(), getppid());

    f1 = fork();
    if (f1 == 0) {
        func1();
        exit(0);
    } 

    sleep(10);

    waitpid(f1,&status,WNOHANG);

    // verifica se o processo filho acabou
    if (WIFSIGNALED(status) == 0){
        int ret = kill(f1, 9);
    }

    // termine se ele nao tiver finalizado!
    
    return 0;
}