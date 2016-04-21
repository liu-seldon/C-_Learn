#include "Derived.h"
using namespace::std;

void Derived::print(ostream& out) {
    out << "Derived print" << endl;
}

ostream& operator<<(ostream& out, const Derived& d) {
    out << d.name << endl;
    return out;
}
