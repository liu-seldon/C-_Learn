#include <stdio.h>

long calculateC(long total, long num) {
    long count = 1;
    long div = 1;
    long n = num;
    long t = total;
    for(long i = 0; i < n; i++) {
        count *=(total--);
        div *=(num--);
        printf("count is %d, div is %d\n", count, div);
    }
    count /= div; 
    printf("total is %d, c is %d, count is %d\n", t, n, count);
    return count;

}

int jumpFloor(int number) {
    int count = 0;
    for (int x = 0; x <= number; x++) {
        for (int y = 0; y <= number/2; y++)  {
            if((x+2*y) ==number) {
                count += calculateC(x + y, y);
            }
        }
    }
    return count;

}

int main() {
    int count = jumpFloor(29);
    printf("count is %d\n", count);
    return 0;
}
