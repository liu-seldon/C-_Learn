#include <iostream>
#include <map>
using namespace::std;

int main() {
    string word;
    map<string, int> word_count;
    while(cin >> word, !cin.eof()) {
        ++word_count[word];
    }
    map<string, int>::iterator itr = word_count.begin();
    while(itr != word_count.end()) {
        cout << itr->first << " " << itr->second << endl;
        itr++;
    }
    return 0;
}
