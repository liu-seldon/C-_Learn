#include <stdio.h>

#include "utils.h"

int weakSym;
int print(const char* str) __attribute__((weak));
int main() {
    print_num(weakSym);
    if (print) {
        print("hello, world!\n");
    }
    return 0;
}
