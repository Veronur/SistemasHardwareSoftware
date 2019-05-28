#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void *tarefa_print_i(void *arg){
    int *i = (int *)arg;
    
    printf("%d\n",*i);
}

int main(){
    
    int *vi=malloc(sizeof(int)*4);
    pthread_t *tids=malloc(sizeof(pthread_t)*4);

    for(int i =0; i<4; i++){
        vi[i]=i;
        int error = pthread_create(&tids[i], NULL, tarefa_print_i, &vi[i]);
        pthread_join(tids[i], NULL);
    }

    return 0;
}   