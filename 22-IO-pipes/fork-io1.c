#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>
void funcao_lenta() {
    for (int i = 0; i < 5; i++) {

        printf("Filho %d", i);
        sleep(2);
        printf(" -- Fim Filho %d\n", i);

    }
}

void funcao_lenta_pai() {
    for (int i = 0; i < 10; i++) {

        printf("Pai %d", i);
        sleep(1);
        printf(" -- Fim Pai %d\n", i);

    }
}

int main(int argc, char *argv[]) {
    /* completar aqui */
    int k;
    int status;
    char buff[5];
    k=open("./",__O_TMPFILE|O_RDWR,0600);

    int f1= fork();

    if (f1 == 0){
        dup2(k,1);
        funcao_lenta();
    }
    else{

        funcao_lenta_pai();
        wait(&status);
        lseek(k, 0, SEEK_SET);
        while(read(k,buff,1)){
            printf("%c",buff[0]);
        }
    }    
    
    return 0;
}
