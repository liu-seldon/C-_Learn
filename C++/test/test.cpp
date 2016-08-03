#include <stdio.h>

int fun(int a){
    printf("%d\n", 1<<5);
    printf("%d\n", a^=(1<<5));
     a^=(1<<5)-1;
      return a;
}

int main() {
    int n = 484;
    int sum = 0;
    for (int i = 1; n > sum; i+=2) {
        sum = sum + i;
    }
    sum = fun(21);
    printf("%d\n", sum);
    return 0;
}
