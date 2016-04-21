#include <iostream>
#include <malloc.h>
#include <stdlib.h>

using namespace::std;

int main() {
    char * ptr;
    ptr = (char *) malloc(sizeof(char) * 256);
    char * temp = ptr;
    for(int i = 0; i < sizeof(ptr); i++, temp++) {
       *temp = 'a'; 
    }
    cout << sizeof(ptr) <<" " << sizeof(&ptr) << " " << sizeof(*ptr) << endl;
    *temp = '\0';
    cout << ptr << endl;
    return 0;
}
