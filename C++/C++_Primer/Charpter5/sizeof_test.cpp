#include <iostream>

using namespace::std;

int main() {
    int array[] = {1, 2, 3, 4, 5,};
    cout << sizeof(array) << endl;
    int (&p)[5] = array;
    cout << sizeof(p) << endl;
    return 0;
}
