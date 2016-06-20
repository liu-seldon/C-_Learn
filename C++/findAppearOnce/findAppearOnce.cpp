#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void printVector(vector<int> data) {
    vector<int>::iterator begin = data.begin();
    while (begin != data.end()) {
        cout << *begin << " ";
        begin++;
    }
    cout << endl;
}
void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
    int count = 0;
    while (!data.empty() || count != 2) {
        vector<int>::iterator pos = find(data.begin()+1, data.end(), *data.begin());
        printVector(data);
        if(pos != data.end()) {
            data.erase(pos);
            data.erase(data.begin());
        } else {
            if (count == 0) {
                *num1 = *data.begin(); 
            } else {
                *num2 = *data.begin();
            }
            data.erase(data.begin());
            cout << " data is empty " << data.empty() << endl;
            //if (data.begin() == data.end()) {
                //return;
            //}
            count++;
        }
    }
}

int main() {
    int data[] = {2, 4, 3, 5, 3, 2, 5, 6};
    int size = sizeof(data) / sizeof(int);
    vector<int> v(data, data + size);
    int num1 = 0, num2 = 0;
    int* p1 = &num1, *p2 = &num2;
    FindNumsAppearOnce(v, p1, p2);
    cout << num1 << " " << num2 << endl;
    return 0; 
}
