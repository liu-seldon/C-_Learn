#include <iostream>
#include <stdlib.h>

using namespace std;

class TestNew {
    public:
        void* operator new(size_t t) { cout << "custom new" << endl; return malloc(sizeof(TestNew));}
        int n;
};

int main() {
    TestNew* t =new TestNew;
    if (t != NULL) {
        t->n = 4;
        cout << t->n << endl;
    } else {
        cout << "new error" << endl;
    }
    return 0;
}
