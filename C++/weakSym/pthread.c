#include <stdio.h>
#include <pthread.h>

//int pthread_create(pthread_t*, const pthread_attr_t*, void*(*)(void*), void*) __attribute__ ((weak));
int pthread_create (pthread_t *__restrict __newthread,
              const pthread_attr_t *__restrict __attr,
                    void *(*__start_routine) (void *),
                          void *__restrict __arg) __attribute__ ((weak));
int pthread_join (pthread_t __th, void **__thread_return)  __attribute__ ((weak));

void* handle(void* arg) {
    printf("new thread\n");
}

int main() {
    if (pthread_create) {
        printf("this is muti-thread version!\n");
        pthread_t pid;
        pthread_create(&pid, NULL, handle, NULL);
        void* rel;
        pthread_join(pid, &rel);
    } else {
        printf("this is single-thread version!\n");
    }
    return 0;
}
