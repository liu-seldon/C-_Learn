#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string moveLeft(string str, int step) {
    int length = str.length();
    if(length == 0) {
        return str;
    }
    str.append(str, 0, step); 
    cout << "append str is " << str << endl;
    string temp = str.substr(step, length);
    cout << "sub str is " << temp << endl;
    return temp;
}
string LeftRotateString(string str, int n) {
    int length = str.length();
    if (length <= 0  || !(n %= length)) {
        return str;
    }
    reverse(str.begin(), str.begin() +n);
    reverse(str.begin() + n, str.end());
    reverse(str.begin(), str.end());
    return str;
}

int main() {

    while(!cin.fail()) {
        string str;
        int step;
        cin >> str >> step;
        cout << "new string is " << LeftRotateString(str, step) << endl;
    }
}
