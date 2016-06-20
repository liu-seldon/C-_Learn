#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string reverseWord(string str) {
    string::iterator begin = str.begin();
    int first = str.find(' ', 0);
    int last = 0;
    while(first != -1 && begin + first != str.end()) {
        cout << " index is " <<  first << endl;
        reverse(begin + last, begin+first);
        cout << "temp str is " << str << endl;
        last = ++first;
        first = str.find(' ', first);
    }
    reverse(begin + last, str.end());
    cout << "temp str is " << str << endl;
    reverse(begin, str.end());
    return str;
}

int main() {
    while (!cin.fail()) {
        string str;
        getline(cin, str);
        cout << "str is         " << str << endl;
        cout << "reverse str is " <<  reverseWord(str) << endl;
    }
}
