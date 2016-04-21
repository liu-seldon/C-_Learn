#include <iostream>
#include <limits>
using namespace::std;

int main() {
    int ival;
    while(cin >> ival, !cin.eof()) {
        if (cin.bad()) {
            cout << "error" << endl;
            break;
        }
        if (cin.fail()) {
            cout << "bad data, try again" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
    }

    return 0;
}
