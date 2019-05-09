#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

void main() {
  pid_t f1;
  int status;
  f1 = fork();
  if (f1 == 0) {
    while (1) {
      printf("loop infinito! meu pid: %d\n", getpid());
    }
  }

  wait(&status);
  
  if (WIFSIGNALED(status) == 1){
     printf("Sinal recebido pelo filho : %s",strsignal(status)); 
  }
}