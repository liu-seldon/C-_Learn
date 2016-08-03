#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

vector<string> numberStrs;
string printMinNumber(string result, vector<int> numbers) {
    if (numbers.size() == 1) {
        stringstream ss;
        ss << numbers[0];
        result.append(ss.str());
        numberStrs.push_back(result);
        return result; 
    } 
    for (int i = 0; i < numbers.size(); i++) {
        vector<int> temp = numbers;
        string tempStr(result);
        int num = temp[i];
        stringstream ss;
        ss << num;
        tempStr.append(ss.str());
        temp.erase(temp.begin() + i);
        printMinNumber(tempStr, temp);
    }

    return result;
}

string minString(vector<string> strings) {
    string str;
    if (strings.size() <= 0) {
        string str;
        return str;
    }
    vector<string>::iterator begin = strings.begin();
    vector<string>::iterator min = begin; 
    while (begin != strings.end()) {
        int result = (*min).compare(*begin);
        cout << "first string is " << *min << ", second string is " << *begin << 
            ", result is " << result << endl;
        if (result > 0) {
            min = begin;
        }
        begin++;
    }
    return *min;
}

int compare(const string& str1, const string& str2) {
    string s1 = str1 + str2;
    string s2 = str2 + str1;
    int result = s2.compare(s1);
    cout << "first string is " << s2 <<
        ", second string is " << s1 <<
        " result is " << result << endl;
    if (result < 0) {
        result = 0;
    }
    return result;
}

string PrintMinNumbers(vector<int> numbers) {
    vector<string> numStrings;
    int size = numbers.size();
    if (size < 1) {
        string str;
        return str; 
    }
    for (int i = 0; i < size; i++) {
        stringstream ss;
        ss << numbers[i];
        numStrings.push_back(ss.str());
    } 
    sort(numStrings.begin(), numStrings.end(), compare);
    string result;
    for (int i = 0; i < size; i++) {
        result.append(numStrings[i]);
    }
    return result;

}

int main() {
    int number;
    vector<int> numbers;
    while(!cin.fail()) {
       cin >> number;
       if (number != -1) {
           numbers.push_back(number);
       } else {
           //string result;
           //printMinNumber(result, numbers);
           //cout << "total number is " << numberStrs.size() << endl;
           //vector<string>::iterator begin = numberStrs.begin();
           //while (begin != numberStrs.end()) {
               //cout << *begin++ << " ";
           //}
           //cout << endl;
           //cout << "min string is " << minString(numberStrs) << endl;
           //numberStrs.clear();
           cout << "min num is " << PrintMinNumbers(numbers) << endl;
           numbers.clear();
       }
    }
}
