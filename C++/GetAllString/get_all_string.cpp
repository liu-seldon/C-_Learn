#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

set<string> strs;
void getString(string str, string result);

vector<string> Permutation(string str) {
    vector<string> results;
    string result;
    getString(str, result);
    set<string>::iterator begin = strs.begin();
    while (begin != strs.end()) {
        results.push_back(*begin++);

    }
    sort(results.begin(), results.end());
    return results;

}

void getString(string str, string result) {
    if(str.length() == 1) {
        result.append(str);
        strs.insert(result);
        return;
    }
    for (int i = 0; i < str.length(); i++) {
        string temp(str);
        string tempResult(result);
        tempResult.append(1, temp[i]);
        temp.erase(i, 1);
        getString(temp, tempResult);
    }
}

int main() {
    string str("abc");
    vector<string> result = Permutation(str);
    vector<string>::iterator begin = result.begin();
    while (begin != result.end()) {
        cout << *begin++ << " ";
    }
    cout << endl;
    return 0;
}


