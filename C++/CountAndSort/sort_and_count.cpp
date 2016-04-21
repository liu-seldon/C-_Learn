#include <iostream>
#include "InputData.h"
#include <map>
#include <vector>
#include <set>
#include <algorithm>

using namespace::std;

int main() {
    map<char, InputData> counts;
    string text;
    cin >> text;
    for (int i = 0; i < text.size(); i++) {
        char c = text[i];
        if(counts[c].count == 0) {
            counts[c].count++;
            counts[c].order = counts.size();
            counts[c].data = text[i];
        } else {
            counts[c].count++;
        }
    }

    //vector<InputData> datas;
    set<InputData> datas;
    for(map<char, InputData>::iterator itr = counts.begin(); itr != counts.end(); itr++) {
        //datas.push_back(itr->second);
        datas.insert(itr->second);
    }

    //sort(datas.begin(), datas.end());

    //for(vector<InputData>::reverse_iterator itr = datas.rbegin(); itr != datas.rend(); itr++) {
        //cout << itr->data << itr->count ;
    //}

    for(set<InputData>::reverse_iterator itr = datas.rbegin(); itr != datas.rend(); itr++) {
        cout << itr->data << itr->count ;
    }

    cout << endl;
    return 0;

}
