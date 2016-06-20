#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool IsPopOrder(vector<int> pushV,vector<int> popV) {
    stack<int> data;
    stack<int> popData;
    for (int i = popV.size() - 1; i >= 0; i--) {
        popData.push(popV[i]);
    }
    int size = pushV.size();
    for (int i = 0; i < size; i++) {
        data.push(pushV[i]);
        while (!data.empty() && !popData.empty() && data.top() == popData.top()) {
            data.pop();
            popData.pop();
        }
    }

    return popData.empty();
}

int main() {
    vector<int> pushV;
    for (int i = 1; i <= 5; i++) {
       pushV.push_back(i);
    }

    int popData[] = {4, 3, 5, 1, 2};
    vector<int> popV(popData, popData + 5);
    if (IsPopOrder(pushV, popV)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
