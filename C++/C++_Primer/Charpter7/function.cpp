#include <iostream>
using namespace::std;

void print(const string &);
void print(double);
void fun(int value) {
    void print(int value); 
    //print("Value:");
    print(value);
    print(3.14);
}

int main() {
    fun(12);
}

void print(const string &s) {
    cout << s <<endl;
}

void print(double value) {
    cout << value << endl;
}

void print(int value) {
    cout << value << endl;
}
