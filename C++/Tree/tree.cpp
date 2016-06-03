#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void printVector(vector<int> & v) {
    vector<int>::iterator begin = v.begin();
    while(begin != v.end()) {
        cout << " " << *begin++;
    }
    cout << endl;
}
struct TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in) {
    if (pre.empty() || in.empty()) {
        return NULL;

    }
    struct TreeNode *root = new TreeNode(pre[0]);
    vector<int>::iterator rootIter =  find(in.begin(), in.end(), root->val);
    vector<int> inLeft(in.begin(), rootIter);
    vector<int> inRight(++rootIter, in.end());
    cout << "in Vector: " << endl;
    printVector(inLeft);
    printVector(inRight);
    vector<int>::iterator preBegin = pre.begin();
    vector<int> preLeft(preBegin + 1, preBegin + (rootIter - in.begin()));
    vector<int> preRight(preBegin + (rootIter - in.begin()), pre.end());
    cout << "pre vector: " << endl;
    printVector(preLeft);
    printVector(preRight);
    root->left = reConstructBinaryTree(preLeft, inLeft);
    root->right = reConstructBinaryTree(preRight, inRight);

    return root;

}

int main() {
    vector<int> pre, in;
    int preArray[] = {1, 2, 4, 7, 3, 5, 6, 8,};
    int inArray[] = {4, 7, 2, 1, 5, 3, 8, 6, };
    
    for(int i = 0; i < sizeof(preArray) / sizeof(preArray[0]); i++){
        pre.push_back(preArray[i]);
        in.push_back(inArray[i]);
    }
    cout << sizeof(preArray) / sizeof(preArray[0]) << endl;
    
    reConstructBinaryTree(pre, in);
    return 0;
}
