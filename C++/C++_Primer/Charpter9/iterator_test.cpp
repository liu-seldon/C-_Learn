#include <iostream>
#include <string>
#include <list>
using namespace::std;

int main() {
    list<string> slists;
    string text_word;
    while(cin >> text_word, !cin.eof()) {
        slists.push_back(text_word);

    }
    list<string>::iterator first = slists.begin(), last = slists.end();
    while(first != last) {        
        cout << *first << endl;
        first++;
    }  
    return 0; 
}
