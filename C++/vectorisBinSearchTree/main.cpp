#include <algorithm>
#include <iostream>
#include <vector>
#include "util.h"

using std::cout;
using std::vector;
using std::endl;

bool ABiggerThanB(vector<int> A, vector<int> B) {
    if (A.size() == 0 || B.size() == 0) return true;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    if(A[0] > B[B.size() - 1]) {
        return true;

    }
    return false;

}

bool VerifySquenceOfBST(vector<int> sequence) {
    if (sequence.size() <= 1) {
        return true;
    }
    vector<int> middle(sequence);
    sort(middle.begin(), middle.end());
    int root = sequence[sequence.size() - 1];
    vector<int>::iterator rootIterator = find(middle.begin(), middle.end(), root);
    int leftLength = rootIterator - middle.begin();
    int rightLength = middle.size() - leftLength - 1;
    vector<int> left(sequence.begin(), sequence.begin() + leftLength);
    cout << "left is : ";
    printV_int(left);
    vector<int> right(sequence.begin() + leftLength, sequence.begin() + leftLength + rightLength);
    cout << "right is : ";
    printV_int(right);

    return ABiggerThanB(right, left) && VerifySquenceOfBST(left) && VerifySquenceOfBST(right);
}

int main() {
   //int a[] = {4,8,6,12,16,14,10}; 
   int a[] = {4,6,7,5};
   int len = sizeof(a) / sizeof(a[0]);
   vector<int> data(a, a+len);
   printV_int(data);
   if (VerifySquenceOfBST(data)) {
       cout << "is Bin serarch Tree" << endl;
   } else {
       cout << "error data " << endl;
   }
}
