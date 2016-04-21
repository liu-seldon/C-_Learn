#include <iostream>
using namespace::std;

int main() {
    int *array = new int[10];
    for(int i = 0; i < 10; i++) {
        cout << *(array + i) << " ";
    }
    cout << endl;

    int *array1 = new int[10]();
    for(int i = 0; i < 10; i++) {
        cout << *(array1 + i) << " ";
    }
    cout << endl;
}
