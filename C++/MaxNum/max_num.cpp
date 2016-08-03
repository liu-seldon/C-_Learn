#include <iostream>
#include <stdio.h>
#include <set>
#include <map>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

set<int> nums;
char str[1001];
map<int, set<int> > maps;

void calc(char *str, int start, int end, int count);

int main() {
    while (scanf("%s", str) != EOF) {
        int len = strlen(str);
        cout << "str len is " << len << endl;
        int num = 0;
        calc(str, 0, len - 1, num);
        set<int>::iterator begin = nums.begin();
        printf("%d\n", *begin);
        nums.clear();
        maps.clear();
        cout << "input new str: ";
    }
    return 0;

}

void calc(char *str, int start, int end, int count) {
    int first = start;
    int last = end;
    int num = count;
        
    pair<set<int>::iterator, bool> p =  maps[start].insert(end); 
    if (!p.second) {
        return;
    }
    //cout << first << " " << last << endl;
    while (first <= last && str[first] == str[last]) {
        first++;
        last--;
    }
    if (first >= last) {
        nums.insert(num);
        return;
    }

    if(first < end) {
        num++;
        calc(str, first, last - 1, num);
        calc(str, first + 1, last, num);
        num++;
        calc(str, first + 1, last -1, num);

    }

}
