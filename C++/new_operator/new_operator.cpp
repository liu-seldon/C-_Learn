#include <iostream>
#include <stdlib.h>

using namespace std;

class TestNew {
    public:
        void* operator new(size_t t) { cout << "custom new " << t << endl; return malloc(sizeof(TestNew) + sizeof(int));}
        int n;
};

int main() {
    TestNew* t = new TestNew;
    if (t != NULL) {
        t->n = 4;
        int* p = (int*) t;
        cout << *p << endl;
        p++;
        cout << *p << endl;
        cout << t->n << endl;
    } else {
        cout << "new error" << endl;
    }
    return 0;
}
