#include <iostream>

using namespace std;

int main() {

#if 0 || \
    1
    cout << " test " << endl;
#else 
    cout << " else " << endl;
#endif
}
