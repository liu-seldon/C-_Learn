#include <iostream>
using namespace std;

int main() {
    int a = 15;
    int* p = (int*) &a;
    cout << *p << endl;
    return 0;
}
