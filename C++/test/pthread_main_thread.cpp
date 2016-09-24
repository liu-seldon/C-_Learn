#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;

void* threadFun(void* args) {
    while(1) {
        cout << "new thread" << endl;
        sleep(1);
    }
}

int main() {
    pthread_t tid;

    pthread_create(&tid, NULL, threadFun, NULL);

    int count = 0;
    while (count < 3) {
        cout << "main trhead" << endl;
        count++;
        sleep(1);
    }
    cout << "main thread stop" << endl;
    return 0;
}
