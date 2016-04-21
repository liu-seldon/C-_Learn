#ifndef INHERIT_VIRTUAL_BASE
#define INHERIT_VIRTUAL_BASE
#include <string>
#include <iostream>
using namespace::std;

class Base {
    private:
        string name;
    public:
        Base():name("Base") {
            print(cout);
        }
        virtual void print(ostream& os);
        
        void print() {
            print(cout);
        }

        friend ostream& operator<<(ostream& out, const Base& b);        
};

#endif
