#include <iostream>

using namespace std;

class Solution {
    public:
        bool isNumeric(char* string)
        {
            if(signFirst(string)) {
                string++;
                cout << "sign, move next" << endl;
            }
            if (pointFirst(string)) {
                string++;
            }

            if(numFirst(string)) {
                cout << "number first" << endl;
                int offset = hasE(string);
                if(offset == -1) {
                    cout << "no E" << endl;
                    return isNum(string);
                } else {
                    cout << "has E" << endl;
                    char* temp = string + offset + 1;
                    *(string+offset) = '\0';
                    cout << temp << " " << string << endl;
                    if(isNum(string)) {
                        cout << "E pre is num" << endl;
                        return isInt(temp);
                    }
                    cout << "E pre is no num" << endl;
                    return false;
                }
            }
            return false;
        }

        bool pointFirst(char* str) {
            if (*str == '.') {
                return true;
            }
            return false;
        }

        bool numFirst(char* str) {
            if (*str >= '1' && *str <= '9') {
                return true;
            } 
            return false;
        }

        bool signFirst(char* str) {
            if(*str == '+' || *str == '-') {
                return true;
            }
            return false;
        }

        bool noPoint(char * str) {
            while (*str != '\0') {
                if (*str++ == '.') {
                    return false;
                }
            }
            return true;
        }

        int hasPoint(char* str) {
            int offset = 0;
            while (*(str+ offset) != '\0') {
                if (*(str + offset) == '.') {
                    return offset;
                }
                offset++;
            }
            return -1;
        }

        int hasE(char* str) {
            int offset = 0;
            while (*(str+ offset) != '\0') {
                if (*(str + offset) == 'e' || *(str + offset) == 'E') {
                    return offset;
                }
                offset++;

            }
            return -1;
        }

        bool onlyNum(char* str, int offset) {
            int n = 0;
            while (*str != '\0' && n < offset) {
                if (*str < '0' || *str > '9') {
                    return false;
                }
                str++;
                n++;
            }
            return true;
        }

        bool onlyNum(char* str) {
            while (*str != '\0') {
                if (*str < '0' || *str > '9') {
                    return false;
                }
                str++;
            }
            return true;

        }

        bool isInt(char *str) {
            if (!noPoint(str)) {
                return false;
            }
            if (signFirst(str)) {
                str++; 
            }
            if (numFirst(str)) {
                if (*str == '0') {
                    return false;
                }
                return onlyNum(str);
            }
            return false;
        }

        bool isNotIngegerNum(char* str) {
            int offset = hasPoint(str);
            if(offset <= 0) {
                return false;
            }
            if (onlyNum(str, offset)) {
                cout << "only num from begin to offset" << endl;
                return (onlyNum(str+offset+1));
            }
            return false;
        }

        bool isNum(char* str) {
            if (isInt(str)) {
                return true;
            }
            cout << "is not int" << endl;
            return isNotIngegerNum(str);
        }
};

int main() {
    char num[] = "-.123";
    Solution s;
    if (s.isNumeric(num)) {
        cout << "is num" << endl;
    } else {
        cout << "not num" << endl;
    }
}
