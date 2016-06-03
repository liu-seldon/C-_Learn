#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char* argv[]) {

    if (argc != 2) {
        cout << "input a number" << endl;
        exit(1);
    }

    int n = atoi(argv[1]);
    char nToChar[32];
    sprintf(nToChar, "%x", n);
    cout << nToChar << endl;
    //sprintf(nToChar, "%b", n);
    cout << nToChar << endl;
    return 0;
}
