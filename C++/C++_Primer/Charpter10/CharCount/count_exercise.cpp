#include <iostream>
#include <string>

using namespace::std;

int main() {
    int count = 0;
    string text;
    while(cin >> text, !cin.eof()) {
        for(int i = 0; i < text.size(); i++) {
            if(text[i] == '|') {
                count++;
            }
        }
    }

    cout << count << endl;
}
