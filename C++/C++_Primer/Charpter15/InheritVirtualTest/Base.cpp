#include "Base.h"
using namespace::std;

void Base::print(ostream& out) {
    out << "Base print" << endl;
}

ostream& operator<<(ostream& out, const Base& b) {
    out << b.name << endl;
    return out;
}

