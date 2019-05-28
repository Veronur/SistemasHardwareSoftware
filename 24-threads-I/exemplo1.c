
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
void *minha_thread(void *arg) {
  printf("Hello thread! %d\n", getpid());
  return NULL;
}


void *minha_thread1(void *arg) {
  printf("hahahaha %d\n", getpid());
  return NULL;
}

void *minha_thread2(void *arg) {
  printf("684685465489! %d\n", getpid());
  return NULL;
}

void *minha_thread3(void *arg) {
  printf("!!!!!!! %d\n", getpid());
  return NULL;
}

int main() {
  pthread_t tid, tid1, tid2, tid3;

  int error = pthread_create(&tid, NULL, minha_thread, NULL);

  int error1 = pthread_create(&tid1, NULL, minha_thread1, NULL);

  int error2 = pthread_create(&tid2, NULL, minha_thread2, NULL);

  int error3 = pthread_create(&tid3, NULL, minha_thread3, NULL);
  
  printf("Hello main\n");

  pthread_join(tid, NULL);
  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);
  pthread_join(tid3, NULL);

  return 0;
}
