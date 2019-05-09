#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
struct sigaction s;
int n = 0;

void sig_handler(int num) {
    printf("Chamou Ctrl+C\n");
    n++;
}

int main() {
    
    
    s.sa_handler = sig_handler;
    sigemptyset(&s.sa_mask);

    sigaction(SIGINT, &s, NULL);
    

    printf("Meu pid: %d\n", getpid());

    while(1) {
        //sleep(1);
        if (n==3)
        {
        exit(0);
        }   
    }
    return 0;
}