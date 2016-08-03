#include <iostream>
#include <string>
#include <map>

using namespace std;

class Node {
    public:
        Node() : position(-1), count(0) {}

        int position;
        int count;
};

int FirstNotRepeatingChar(string str) {
    int position = -1;
    char noRepeatChar;
    map<char, Node> chars;
    for (int i = 0; i < str.length(); i++) {
        if (chars.find(str[i]) == chars.end()) {
            Node node;
            node.position = i;
            node.count++;
            chars.insert(pair<char, Node> (str[i], node));
        } else {
            (chars[str[i]]).count++;

        }
    }
    map<char, Node>::iterator begin = chars.begin();

    Node* node = NULL;
    while (begin != chars.end()) {
        if ((begin->second).count == 1) {
            if (node == NULL) {
                node = &(begin->second);
            } else {
                if (node->position > (begin->second).position) {
                    node = &(begin->second);
                }
            } 
        }
        begin++;
    }


    if (node == NULL) {
        return -1;
    } 
    return node->position;
}

int main() {
    string str;
    while (!cin.fail()) {
        cin >> str;
        cout << "no repeat char position is " << FirstNotRepeatingChar(str) << endl;
    }
    return 0;
}
