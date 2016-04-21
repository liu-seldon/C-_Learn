#include <iostream>
#include <sstream>
#include <string>
using namespace::std;
int main() {
    string line, word;
    while (getline(cin, line)) {
        istringstream stream(line);
        while (stream >> word) {
            cout << word << endl;
        }
    }
    return 0;
}
