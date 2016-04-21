#ifndef INHERIT_STATIC_DERIVED
#define INHERIT_STATIC_DERIVED

#include "Base.h"
class Derived  : public Base{
    public:
        int d;
        void set(int n) {
            b = n;
        }
};

#endif
