#include "util.h"
#include <iostream>

using std::cout;
using std::endl;

void printV_int(const vector<int>& data) {
    int size = data.size();
    cout << "size is " << size << endl;
    if (size == 0) {
        return;
    }
    for (int i = 0; i < size - 1; i++) {
        cout << data[i] << " ";
    }
    cout << data[size - 1] << endl;
}
