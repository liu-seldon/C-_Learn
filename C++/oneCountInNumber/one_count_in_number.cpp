#include <iostream>
#include <sys/time.h>
#include <unistd.h>

using namespace std;

int oneCount(int n) {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        int n = i;
        while (n >= 1) {
            if (n % 10 == 1) {
                count++;
            }

            n /= 10;
            cout << i << " ";
        }
        cout << endl;

    }

    return count;
}

int main() {
    struct timeval tv;
    long lastTime;
    while (!cin.fail()) {
        int n = 0;
        cin >> n;

        gettimeofday(&tv, NULL);
        lastTime = tv.tv_sec * 1000 * 1000 + tv.tv_usec;
        cout << "1 numbers in " << n << " is " << oneCount(n) << endl;
        
        gettimeofday(&tv, NULL);
        long spentTime = tv.tv_sec * 1000 * 1000 + tv.tv_usec - lastTime;
        cout << "This calc spents " << spentTime << "ms" << endl;
    }

    return 0;
}
