#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <map>
#include <algorithm>
#include <sys/time.h>
#include <unistd.h>

using namespace std;
class container {
    public:
    class Node {
        int val;
        int pos;
        int v;
        Node* next;
    };
    int insert(Node* node) {
        
    }
};

// 195ms
set<int> datas;
int insert(int data) {
    pair<set<int>::iterator, bool> p = datas.insert(data);
    if(p.second) {
        set<int>::iterator cur = p.first;
        int count = 0; 
        while (cur-- != datas.begin()) {
            count++;
        }
        return count;
    }
    return 0;
}

int InversePairs(vector<int> data) {
    int count = 0;
    if (data.size() == 0) {
        return 0;
    }
    vector<int>::iterator last = data.end() - 1;
    vector<int>::iterator begin = data.begin();
    cout << "size is " << last - begin << endl;
    while (last != data.begin() ) {
        //cout << "insert " << *last << endl;
        count += insert(*last);
        last--;
    }
    //cout << "insert " << *last << endl;
    count += insert(*last);
    cout << "size is " << datas.size() << endl;
    return count % 1000000007;
}

// 46S
int mergeOnce(int a[], int start, int end) {
    int key = a[start];
    int first = start;
    int last = end;
    while (first < last) {

        while (first < last && a[last] >= key) {
            --last;
        }
        a[first] = a[last];
        while (first < last && a[first] <= key) {
            ++first;
        }
        a[last] = a[first];
    }
    a[first] = key;
    //cout << "position is " << first << endl;
    //for (int i = start; i <= end; i++) {
        //cout << a[i] << " ";
    //}
    //cout << endl;
    return first - start;
}

int inversePairs(vector<int> data) {
    int size = data.size();
    int count = 0;
    if (size <= 0) {
        return count;
    }
    int *dataA = new int[size];
    for (int i = 1; i <= size; i++) {
       dataA[size - i] = data[size - i];
       int c = mergeOnce(dataA, size-i, size-1); 
       //cout << "num " << data[size - i] << " count is " << c << endl;
       count += c;
    } 
    return count;
}

int inversePairs1(vector<int> data) {
    int size = data.size();
    int count = 0;
    if (size <= 0) {
        return count;
    }
    int *dataA = new int[size];
    vector<int> dataV(size, 0);
    map<int, int> dataM;
    for (int i = 0; i < size; i++) {
        dataM[data[i]] = i;
        dataA[i] = 0;
    }
    map<int, int>::reverse_iterator begin = dataM.rbegin();
    int pos = 0;
    while (begin != dataM.rend()) {
        if (pos) {
           dataA[begin->second]++; 
           count++;
           dataV[begin->second]++;
        } 
        pos++;
        begin++;
    }
    return 0; 
}

int inversePairs2(vector<int> data) {
    map<int, int> datas;
    vector<int> indexs;
    int size = data.size();
    for (int i = 0; i < size; i++) {
        datas[i] = data[i];
        indexs.push_back(i);
    }
    int count = 0;
    map<int, int>::reverse_iterator begin = datas.rbegin();
    while (begin != datas.rend()) {
        int index = begin->second;
         vector<int>::iterator pos; 
         if ( (pos = find(indexs.begin(), indexs.end(), index) ) != indexs.end()) {
             count += indexs.end() - pos - 1;
             indexs.erase(pos);
         }
        begin++;
    }
    return count;
}

int main() {
    const int SIZE = 2 * 100000;
    int array[SIZE];
    for (int i = 1; i < SIZE; i++) {
        array[i - 1] = i;
    }
    array[SIZE - 1] = 0;
    vector<int> data(array, array + sizeof(array) / sizeof(array[0]));
    
    struct timeval tv;
    long lastTime;
    gettimeofday(&tv, NULL);
    lastTime = tv.tv_sec * 1000 * 1000 + tv.tv_usec;
    int count = inversePairs2(data);
    cout << "inverse pairs is " << count << endl;
    gettimeofday(&tv, NULL);
    long spentTime = tv.tv_sec * 1000 * 1000 + tv.tv_usec - lastTime;
    cout << "spentTime is " << spentTime / 1000 << endl;
}

