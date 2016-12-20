#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> data) {
    for (int i = 0 ; i < data.size(); i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

int InversePairs(vector<int> data) {
    if (data.size() == 0 || data.size() == 1) {
        return 0;

    }
    if (data.size() == 2) {
        if (data[0] > data[1]) {
            return 1;

        } else {
            return 0;

        }

    }
    int count = 0;
    int len = data.size();
    int preLen = len / 2;
    int subLen = len - preLen;
    vector<int> pre(data.begin(), data.begin() + preLen + 1);
    print(pre);

    vector<int> sub(data.begin() + preLen + 1, data.end());
    print(sub);
    int preCount = InversePairs(pre);
    cout << "preCount is " << preCount << endl;
    int subCount = InversePairs(sub);
    cout << "subCount is " << subCount << endl;
    count = preCount + subCount;
    for (int i = 0; i < preLen + 1; i++) {
        for (int j = 0; j < subLen; j++) {
            if (data[i] > data[preLen + j]) {
                cout << "inverse pair is " << data[i] << " " << data[preLen + j] << endl;
                count++;

            }

        }

    }
    return count % 1000000007;

}

int inversePairs(vector<int> data) {
    if (data.size() == 0 || data.size() == 1) {
        return 0;
    }
    if (data.size() == 2) {
        return data[0] > data[1] ? 1 : 0;
    }

    int count = 0;
    int step = 1;
    int len = data.size();
    int lastIndex = -1;
    int n = 0;
    do {
        n++;
        for (int i = 0; i < len; i+= 2 * step) {
            for (int j = i; j < i + step; j++) {
                for (int k = 0; k < step; k++) {
                    if (data[i + step + k] < data[j]) {
                        count++;
                    }
                }
            }
            lastIndex = i;
        } 
        if (lastIndex < len) {
            cout << "lastIndex is " << lastIndex << endl;
            for (int i = lastIndex; i < lastIndex + step; i ++) {
                for (int j = lastIndex + step; j < len; j++ ) {
                    if (data[i] > data[j]) {
                        count++;
                    }
                }
            }
        }
        step *= 2;
    } while(2 * step <= len); 
    
    cout << "repeat count is " << n << endl;
    return count;
}

int main() {
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 0};
    int len = sizeof(array) / sizeof(array[0]);
    vector<int> data(array, array + len);
    for (int i = 0; i < len; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
    cout << "size is " << data.size() << endl;
    int count = inversePairs(data);
    cout << "count is " << count << endl;
}
