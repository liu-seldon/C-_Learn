#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
    public:
        vector<int> maxInWindows(const vector<int>& num, unsigned int size)
        {
            int max = -1;
            int position = -1;
            int begin = 0;
            vector<int> result;
            int numSize = num.size();
            while (begin + size <= numSize) {
                if (position < begin || position >= begin + size) {
                    vector<int> temp = findMax(num, begin, begin + size);
                    max = temp[0];
                    position = temp[1];

                } else {
                    if (max < num[begin + size - 1]) {
                        max = num[begin + size - 1];
                        position = begin + size -1;

                    }

                }
                result.push_back(max);
                begin++;

            }
            return result;

        }

        vector<int> findMax(const vector<int>& num, int begin, int end) {
            vector<int> result;
            int max = num[begin];
            int position = begin;
            for (int i = begin; i < end; i++) {
                cout << num[i] << " ";
                if(max < num[i]) {
                    max = num[i];
                    position = i;

                }

            }
            cout << "; max is " << max << endl;
            result.push_back(max);
            result.push_back(position);
            return result;

        }

};

vector<int> maxInWindows(const vector<int>& a, unsigned int k){
    vector<int> res;
    deque<int> s;
    for(unsigned int i = 0; i < a.size(); ++i){
        while(s.size() && a[s.back()] <= a[i]) s.pop_back();
        while(s.size() && i - s.front() + 1 > k) s.pop_front();
        s.push_back(i);
    
        if(k && i + 1 >= k) {
            res.push_back(a[s.front()]);
            cout << a[s.front()] << endl;
        }
    }
    return res;

}

int main() {
    int arrays[] = {2,3,4,2,6,2,5,1};
    vector<int> num(arrays, arrays + (sizeof(arrays) / sizeof(arrays[0])));
    Solution s;
    vector<int> maxs = maxInWindows(num, 3);
    vector<int>::iterator begin = maxs.begin();
    while (begin != maxs.end()) {
        cout << *begin++ << " " ;
    }
    cout << endl;
    return 0;

}

