#include <iostream>
#include "Base.h"
#include "Derived.h"

using namespace::std;

int Base::n = 10;

int main() {
    Derived d;
    Base b;
    b.n = 5;
    d.set(5);
    Base b1(d);
    cout << b.n << " " << d.n << endl;
    cout << b1.b << endl;
    return 0;
}
