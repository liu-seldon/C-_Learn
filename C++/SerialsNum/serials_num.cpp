#include <iostream>
#include <vector>
#include <map>
#include <math.h>

using namespace std;

vector<vector<int> > findContinuousSequence(int sum) {
    vector<vector<int> > sequeue;
    if (sum <= 0) {
        return sequeue;
    }
    int numCounts = (int)ceil(sum / 2.0);
    cout << "max numCounts is " << numCounts << endl;
    for (int n = numCounts; n >= 2; n--) {
        for (int i = 1; i < numCounts; i++) {
            vector<int> temp;
            int result = 0;
            cout << "check sequeue is "; 
            for (int x = 0; x <n; x++) {
                cout << i + x << " ";
                result += (i+x);
                temp.push_back(i + x);      
            }
            cout << endl;
            if (result < sum) {
                continue;
            } else if (result == sum) {
                sequeue.push_back(temp);
            } else if (result > sum) {
                break;
            }
        }
    }

    return sequeue;
}

int main() {
    while (!cin.fail()) {
        int sum;
        cin >> sum;
        vector<vector<int> > sequeue = findContinuousSequence(sum);
        for (int i = 0; i < sequeue.size(); i++) {
            vector<int> temp = sequeue[i];
            vector<int>::iterator begin = temp.begin();
            while (begin != temp.end()) {
                cout << *begin << " " ;
                begin++;
            }
            cout << endl;
        }
    }
    return 0;
}
