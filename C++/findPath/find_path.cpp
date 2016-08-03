#include <iostream>
#include <stack>
#include <vector>
#include <set>
#include <string.h>

using namespace std;

class Char {
    public:
        int position;
        int index;
        int direction;
        Char(int pos):position(pos), direction(0), index(0) {

        }
};

bool hasPath(char* matrix, int rows, int cols, char* str) {
    stack<Char*> chars;
    vector<int> postions;
    int i = 0;
    while (i < rows * cols) {
        if (*(matrix + i) == *str) {
            postions.push_back(i);
        }
        i++;
    }
    set<int> nodes;
    vector<int>::iterator begin = postions.begin();
    int len = strlen(str); 
    while (begin != postions.end()) {
        cout << "beign is " << *begin << " " << matrix[*begin] << endl;
        Char* head = new Char(*begin);
        chars.push(head);
        nodes.clear();
        nodes.insert(head->position);
        while (!chars.empty()) {
            Char* node = chars.top();
            cout << "node is " << node->position << " " << matrix[node->position] << endl;
            if (node->direction >= 4) {
                nodes.erase(node->position);
                chars.pop();
                continue;
            }
            if (node->index == len - 1) {
                return true;
            }
            int nowPos = node->position;
            switch(node->direction) {
                case 0:{
                           int upPosition = nowPos - cols;
                           if(upPosition < 0) {
                               break;
                           } else {
                               if (matrix[upPosition] == str[node->index + 1]) {
                                   if (!(nodes.insert(upPosition).second)) {
                                       break;
                                   }
                                   Char* upChar = new Char(upPosition);
                                   upChar->index = node->index + 1;
                                   chars.push(upChar);
                               }
                           } 
                           break;
                       }
                case 1: {
                            int downPosition = node->position + cols;
                            if(downPosition >= rows * cols) {
                                break;
                            } else {
                               if (matrix[downPosition] == str[node->index + 1]) {
                                   if (!nodes.insert(downPosition).second) {
                                       break;
                                   }
                                   Char* downChar = new Char(downPosition);
                                   downChar->index = node->index + 1;
                                   chars.push(downChar);
                               }
                            }
                            break;
                        }
                case 2: {
                            if (nowPos % cols == 0) {
                                break;
                            }
                            int leftPosition = nowPos - 1;
                            if (matrix[leftPosition] == str[node->index + 1]) {
                                if (!nodes.insert(leftPosition).second) {
                                    break;
                                }
                                Char* leftChar = new Char(leftPosition);
                                leftChar->index = node->index + 1;
                                chars.push(leftChar);
                            }
                            break;
                        }
                case 3: {
                            if ((nowPos + 1) % cols == 0) {
                                break;
                            }
                            int rightPosition = nowPos + 1;
                            if (matrix[rightPosition] == str[node->index + 1]) {
                                if (!nodes.insert(rightPosition).second) {
                                    break;
                                }
                                Char* rightChar = new Char(rightPosition);
                                rightChar->index = node->index + 1;
                                chars.push(rightChar);
                            }
                            break;
                        }
            } 
            node->direction++;
        }
        begin++;
    }

    return false;

}

int main () {
    char* matrix = "abcesfcsadee";
    int rows = 3;
    int cols = 4;
    char* str1 = "bcceda";
    char* str2 = "abcb";
    if (hasPath(matrix, 3, 4, str1)) {
        cout << "has str1" << endl;
    }
    if (hasPath(matrix, 3, 4, str2)) {
        cout << "has str2" << endl;
    }
    return 0;
}
