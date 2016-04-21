#include <stdio.h>

int main() {
    unsigned char i = 0x1;
    i = i << 4;
    printf("%d\n", i); 
    i << 1;
    printf("%d\n", i); 
    i << 1;
    printf("%d\n", i); 
    i >> 1;
    printf("%d\n", i); 
    i >> 1;
    printf("%d\n", i); 
}
