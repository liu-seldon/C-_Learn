#include <stdio.h>
#define print(a) printf("%p\n", a)

const int ZERO = 0;
int main() {
    const int* p  = &ZERO;
    int zero = 0;
    int* p1 = &zero;
    int* p2 = 0;
    //printf("%p", p1);
    print(p);
    print(p1);
    print(p2);    
}
