#include <stdio.h>

int fun(int x) {
    int p;
    if (x == 0 || x == 1) {
        return 3;
    }
    p = x - fun(x - 2);
    return p;
}

int main() {
    printf("%d\n", fun(9));
    return 0;
}
