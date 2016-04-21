#include <iostream>
using namespace::std;

int main() {
    int value = 1024;
    int *p = &value;
    int **pp = &p;
    int *p2 = *pp;
    cout << "value is " << value << "\n"
        << "*p " << value << "\n"
        << "**pp" << **pp << ", *pp" << *pp << "\n"
        << "*p2" << *p2 << endl; 
}
