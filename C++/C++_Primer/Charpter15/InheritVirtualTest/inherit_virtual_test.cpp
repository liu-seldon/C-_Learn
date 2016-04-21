#include <iostream>
#include "Base.h"
#include "Derived.h"

using namespace::std;

int main() {
    Base b;
    Derived d;
    Base* d1 = new Derived;
    d1->print(cout);
    d1->print(); //模板方法模式
    Base& d2 = d;
    cout << d2 << endl;
    cout << b << endl;
    return 0;
}
