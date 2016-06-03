#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include "BlockQueue.h"

using namespace std;

BlockQueue<int> queue(100);
int count = 0;

void* thread1(void * args) {
	while (count < 1000) {
		if (queue.put(count)) {
			cout << "push " << count++ << endl;
		}
	}
}

void* thread2(void* args) {
	int item;
	if (queue.take(item)) {
		cout << "take " << item << endl;
	}
}
int main() {
	pthread_t pid;
	pthread_create(&pid, NULL, thread1, NULL);
	while(1) {
		int item;
		if (queue.take(item, 1000 * 5)) {
			cout << "take " << item << endl;
		} else {
			cout << "take time out" << endl;
			break;
		}
	}
}