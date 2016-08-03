#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>


using namespace std;

int main() {
    char array[][10] = {"hello", "world"};
    char (*p)[10] = array;
    vector<string> strs;
    strs.push_back("hello");
    strs.push_back("world");
    vector<string>::iterator begin = strs.begin();
    printf("%s\n", (*begin).c_str());
    //cout << *p << endl;

}
