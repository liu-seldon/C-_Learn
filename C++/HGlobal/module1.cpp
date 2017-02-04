#include "header.h"
#include <iostream>

using namespace std;

void print() {
    cout << "PI is " << PI << endl;    
#ifdef DEBUG
    cout << "module1 -- define debug" << endl;
#endif
}
