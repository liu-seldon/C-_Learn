#ifndef INHERIT_VIRTUAL_DERIVED
#define INHERIT_VIRTUAL_DERIVED

#include "Base.h"
#include <iostream>
#include <string>
using namespace::std;

class Derived : public Base {
    private:
        string name;
    public:
        Derived():name("Derived"){
            print(cout);
        }

        virtual void  print(ostream& out);
        friend ostream& operator<<(ostream& out, const Derived& d);
};

#endif
