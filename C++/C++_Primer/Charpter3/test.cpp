#include <string>
#include <iostream>
#include <vector>
using std::string;
using std::cout;
using std::vector;
using std::endl;
string s;

int main() {
    string s1;
    cout << s;
    cout << s1;
    vector<string> strings;
    for(int index = 0; index != 10; index++) {
        strings.push_back("test");
    }

    for(vector<string>::iterator iter = strings.begin(); iter != strings.end(); ++iter) {
        cout << *iter <<endl;
    }
}
