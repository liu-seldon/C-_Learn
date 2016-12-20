#include <iostream>

using namespace std;

class Test {
    int a;
    
    public:
    Test():a(5) {}
    void print() {
        cout << "Hello, world!" << endl;
        cout << a << endl;
    }
};

void print() {
    cout << "global print" << endl;
}

int main() {
   typedef void (*FuncitonPointer)(void*);
   FuncitonPointer p = reinterpret_cast<FuncitonPointer> (&Test::print);
   typedef void (Test::*FP)();
   FP f_p = &Test::print;
   Test t;
   (t.*f_p)();
   p(&t);
   return 0;
}
