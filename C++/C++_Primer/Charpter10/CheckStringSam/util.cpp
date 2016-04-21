#include "util.h"
#include <iostream>
#include <map>
#include <string>

bool checkSam(string stringA, string stringB) {
    int length = stringA.size();
    if(length != stringB.size()) {
        return false;

    }
    map<char, int> stringAChar;
    map<char, int> stringBChar;
    for(int i = 0; i < length; i++) {
        ++stringAChar[stringA[i]];
        ++stringBChar[stringB[i]];

    }

    map<char, int>::iterator mapAItr = stringAChar.begin();
    map<char, int>::iterator mapBItr = stringBChar.begin();

    while(mapAItr != stringAChar.end() && mapBItr != stringBChar.end()) {
        cout << mapAItr->first << " is " << mapAItr->second << endl;
        cout << mapBItr->first << " is " << mapBItr->second << endl;
        if(mapAItr->first != mapBItr->first || mapAItr->second != mapBItr->second) {
            break;

        }
        mapAItr++;
        mapBItr++;

    }

    if(mapAItr == stringAChar.end() && mapBItr == stringBChar.end()) {
        return true;

    } else {
        return false;

    }

}
