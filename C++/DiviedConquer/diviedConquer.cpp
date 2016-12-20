#include <iostream>
using namespace std;

int count(int* start, int* end, int length) {
    int c = 0;
    if (length == 1) {
        return 0;
    }
    if (length == 2) {
        if ( *end < *start) {
            cout << *end << " " << *start << endl;
            return 1;
        } else {
            return 0;
        }
    }
    int preLen = length / 2;
    int subLen = length - preLen;
    int preCount = count(start, start + preLen - 1, preLen);
    cout << "preCount is " << preCount << endl;
    int subCount = count(start + preLen, end, subLen);
    cout << "subCount is " << subCount << endl;
    c = preCount + subCount;
    for (int i = 0; i < preLen; i++) {
        for (int j = 0; j < subLen; j++) {
            if (start[preLen + j] < start[i]) {
                cout << start[preLen + j] << " " << start[i] << endl;
                c++;
            }
        }
    }
    return c;

}

int main() {
    int numbs[] = {2, 1, 3, 6, 4, 5, 7};
    int length = sizeof(numbs) / sizeof(numbs[0]);
    int c = count(numbs, numbs + length - 1, length);
    cout << "count is " << c << endl;
}
