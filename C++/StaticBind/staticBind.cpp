#include <stdio.h>

class A {
    public:
        void test() {
            printf("Hello, world!\n");
        }
};

int main() {
    A* pA = NULL;
    pA->test();
    return 0;
}
