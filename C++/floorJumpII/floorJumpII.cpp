#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
long jumpFloorII(int number) {
    if (number == 0 ) {
        return 0;

    }
    if (number == 1 ) {
        return 1;

    }

    long *counts = (long*) malloc(sizeof(long) * number);
    int index = 0;
    int n_0 = 1;
    int n_1 = 1;
    int n_x = 0;
    *(counts + index++) = 1;
    *(counts + index++) = 1;
    for (int i = number; i >= 2; i--) {
        long x = 0;
        for(int i = 0; i < index; i++) {
            x += *(counts + i);
        }
        *(counts + index++) = x;
    }

    return *(counts + (index-1));

}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "./a.out number" << endl;
        exit(1);
    }
    int number = atoi(argv[1]);
    long count = jumpFloorII(number);
    cout << "count is " << count << endl;
}
