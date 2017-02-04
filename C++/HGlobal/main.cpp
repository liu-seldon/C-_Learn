#include "header.h"
#include <iostream>

using namespace std;

void print();

int main() {
    cout << "main -- PI is " << PI << endl;
    print();
#ifdef DEBUG
    cout << "main -- define debug" << endl;
#endif
}
