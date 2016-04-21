#include <iostream>
#include <algorithm>
#include <vector>

using namespace::std;

int main() {

    vector<int> gifts;
    int gift;
    char c;
    while(cin >> gift >>c, !cin.fail()) {
        gifts.push_back(gift);
    }

    sort(gifts.begin(), gifts.end());
    int n = gifts.size();
    cout << "size is " << n << endl;
    vector<int>::iterator giftFirst = find(gifts.begin(), gifts.end(), *(gifts.begin() + n / 2));
    vector<int>::reverse_iterator giftLast = find(gifts.rbegin(), gifts.rend(), *(gifts.begin() + n / 2));
    if(giftFirst != gifts.end()) {
        int firstPos = giftFirst - gifts.begin();
        int lastPos = n - (giftLast - gifts.rbegin());
        if(lastPos - firstPos > n /2) {
            cout << *(gifts.begin() + n / 2) << endl;
        } else {
            cout << 0 << endl;
        }
    }
}
