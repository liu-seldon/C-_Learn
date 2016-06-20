#include <iostream>
#include <sys/time.h>
#include <unistd.h>
#include <set>
#include <algorithm>

using namespace std;
set<long> uglyNumbers;

bool isUglyNumber(int number) {
    while (number % 2 == 0) {
        number /= 2;
    }
    while (number % 3 == 0) {
        number /= 3;
    }
    while (number % 5 == 0) {
        number /= 5;
    }
    if (number == 1) {
        return true;
    } else {
        return false;
    }
}

void print() {
    
    set<long>::iterator begin = uglyNumbers.begin();
    while (begin != uglyNumbers.end()) {
        cout << *begin++ << " ";
    }
    cout << endl;
}

void insert(long value) {
    if (value > 0) {
        uglyNumbers.insert(value);
    }
}

void generateUglyNumbers(int index) {
    uglyNumbers.clear();
    uglyNumbers.insert(1L);
    int count = 0;
    while (count < index) {
        set<long>::iterator begin = uglyNumbers.begin(); 
        for (int i = 0; i < count; i++,begin++);
        long value = *begin;
        insert(value * 2);
        insert(value * 3);
        insert(value * 5);
        count++;
    }
}

int getUglyNumberNormal(int index) {
    int count = 1;
    long uglyNumber = 1;
    if (index <= 0) {
        return 0;

    }
    while (count < index) {
        if (isUglyNumber(++uglyNumber)) {
            count++;
            cout << uglyNumber << " ";
        }
    }
    cout << endl;
    return uglyNumber;
}

int getUglyNumber(int index) {
    
    int num = getUglyNumberNormal(index);
    
    generateUglyNumbers(index);
    print();
    set<long>::iterator begin = uglyNumbers.begin();
    for (int i = 1; i < index; i++,begin++);
    if (num != (int)(*begin)) {
        cout << "error, right is " << num << endl;
    }
    return (int)(*begin);
}

int main() {
    struct timeval tv;
    long lastTime;
    int index;
    cin >> index;
    while (index > 0) {
        gettimeofday(&tv, NULL);
        lastTime = tv.tv_sec * 1000 * 1000 + tv.tv_usec;
        long uglyNumber = getUglyNumber(index);
        gettimeofday(&tv, NULL);
        long spentTime = tv.tv_sec * 1000 * 1000 + tv.tv_usec - lastTime;
        cout << "spentTime is " << spentTime / 1000 << ", uglyNumber is " << uglyNumber << endl;
        cin >> index;
    } 
    return 0;
}
