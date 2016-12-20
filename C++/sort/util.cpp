#include "util.h"

#include <iostream>
#include <unistd.h>
#include <sys/time.h>
#include <stdlib.h>
#include <time.h>

vector<int> createData(int count, int range){
    srand((unsigned)time(NULL));
    vector<int> data;
    for (int i = 0; i < count; i++) {
        data.push_back(rand() % range);
    }
    return data;
}

void printVector_int(vector<int>& data) {
    cout << "data : ";
    for (int i = 0; i < data.size(); i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

long getTime() {
    struct timeval tv;
    long time;
    gettimeofday(&tv, NULL);
    time = tv.tv_sec * 1000 * 1000 + tv.tv_usec;
    return time / 1000;
}

void print(int* array, int len) {
    for(int i = 0; i < len - 1; i++){
        cout << array[i] << " ";
    }
    cout << array[len - 1] << endl;
}
