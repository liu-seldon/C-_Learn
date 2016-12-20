#include <iostream>
#include <vector>
#include <unistd.h>
#include <stdlib.h>

#include "util.h"

using namespace std;

int sortMerge(int* array, int s, int m, int e, int * temp) {
    int start = s;
    int mid = m;
    int end = e;
    int index = 0;
    while (mid >= s && end > m) {
        if(array[mid] > array[end]) {
            
            //cout << "1 "<<"start is " << mid << "; end is " << end << "; "<<  array[mid] << " " << array[end] << endl;
           temp[index++] = array[mid--]; 
        } else {
            //cout << "2 "<<"start is " << mid << "; end is " << end << "; "<<  array[mid] << " " << array[end] << endl;
            temp[index++] = array[end--];
        } 
    }
    while (mid >= s) {
        //cout << "3 "<<"start is " << mid << "; "<< array[mid] << endl;
        temp[index++] = array[mid--];
    }
    while (end > m) {
        //cout << "4 "<<"end is " << end << "; " << array[end] << endl;
        temp[index++] = array[end--];
    }
    //print(temp, index);
    for (int i = 0; i < index; i++) {
        //cout << "5 "<<"i is " << i << "; " << temp[i] << endl;
        array[e - i] = temp[i];
    }
}
int sortCore(int* array, int start, int end, int* temp) {
   if (start < end) {
       int mid = (start + end) / 2;
       sortCore(array, start, mid, temp);
       sortCore(array, mid + 1, end, temp);
       sortMerge(array, start, mid, end, temp);
   } 
}

int sort(int* array, int len) {
    int* temp = new int[len];
    sortCore(array, 0, len-1, temp);
}

int main(int argc, char** argv) {
    int count;
    int range;
    if (argc == 1) {
        count = 10;
        range = 10;

    } else if ( argc == 2 ) {
        count = atoi(*(argv + 1));
        range = 10;

    } else {
        count = atoi(*(argv + 1));
        range = atoi(*(argv + 2));

    }
    vector<int> data = createData(count, range);
    int len = data.size();
    int* array = new int[len];
    for (int i = 0; i < len; i++) {
        array[i] = data[i];
    }
    //printVector_int(data); 
    //print(array, len);
    cout << "------------------------------------------" << endl;
    long lastTime = getTime();
    sort(array, len);
    cout << "spent time is " << getTime() - lastTime << endl;
    //print(array, len);
}
