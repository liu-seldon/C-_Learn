#include <stdio.h>

int main() {
    const int i = 0; 
    int *j = (int *) &i; 
    *j = 1; 
    printf("%d,%d", i, *j);
}
