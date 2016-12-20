#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <stdlib.h>

#include "util.h"

using namespace std;

long InversePairs_1(vector<int> data) {
    if (data.size() == 0) {
        return 0;
    }
    int len = data.size();
    int step = 2;
    long P = 0;
    while (step/2 <= len) {
        for (int i = 0; i < len; i += step) {

            for (int j = 0; j < step / 2 && (i + j) < len; j++) {
                for (int k = 0; k < step / 2 && (i + step / 2 + k < len); k++) {
                    if (data[i + j] > data[i + step / 2 + k]) {
                        P++;
                    }
                    //cout << "Pair is : " << data[i + j] << " " << data[i + step / 2 + k] << endl;
                }
            }
        }
        step *= 2;
    }
    return P % 1000000007;
}

long InversePairs_2(vector<int> data) {
    long P = 0;
    for (int i = 0; i < data.size(); i++) {
        for (int j = i + 1; j < data.size(); j++) {
            if (data[i] > data[j]) {
                P++;
            } 
        }
    }
    return P;
}

long InversePairs_3(vector<int> data) {
    long P = 0;
    int size = data.size();
    map<int, vector<int> > maps;
    for (int i = 0; i < size; i++) {
        maps[data[i]].push_back(i);
    }
    map<int, vector<int> >::reverse_iterator begin = maps.rbegin();
    int remain = size;
    while (begin != maps.rend()) {
        vector<int> p = begin->second;

        int maxInversePairs = remain - p.size();
        cout << "******************************************************" << endl;
        cout << "num : " << begin->first << "maxInversePairs is " << maxInversePairs << endl;
        for(int i = 0; i < p.size();  i++) {
           int position = p[i];
           int inversePairs = size - 1 - position;
           int count = inversePairs > maxInversePairs ? maxInversePairs : inversePairs;
           cout << "position is : " << position << "; inversePairs is " << count << endl;
           P += count;
        }
        remain -= p.size();
        begin++;
    }
    return P;
}

long InversePairs_4(vector<int> data) {
    long P = 0;
    int size = data.size();
    map<int, vector<int> > maps;
    for (int i = size - 1; i >= 0; i--) {
        maps[data[i]].push_back(i);
        map<int, vector<int> >::iterator now = maps.find(data[i]);
        map<int, vector<int> >::iterator begin = maps.begin();
        while (now != begin) {
            P += (begin->second).size();
            begin++;
        }
    }
    return P;
}

int MergeArray(int arry[],int start,int mid,int end,int temp[]) {
    int i=mid;
    int j=end;
    int k=0;
    int count=0;
    while(i>=start&&j>mid) {
        if(arry[i]>arry[j]) {
            temp[k++]=arry[i--];
            count+=j-mid;
        } else {
            temp[k++]=arry[j--];
        }
    }
    while(i>=start) {
        temp[k++]=arry[i--];
    }

    while(j>mid) {
        temp[k++]=arry[j--];
    }

    for(i=0;i<k;i++)
        arry[end-i]=temp[i];
    return count;
}

int InversePairsCore(int arry[],int start,int end,int temp[])
{
    int inversions = 0;  
    if(start<end)
    {
        int mid=(start+end)/2;
        inversions+=InversePairsCore(arry,start,mid,temp);
        inversions+=InversePairsCore(arry,mid+1,end,temp);
        inversions+=MergeArray(arry,start,mid,end,temp);
    }
    return inversions;
}


int InversePairs(int arry[],int len)
{
    int *temp=new int[len];
    int count=InversePairsCore(arry,0,len-1,temp);
    delete[] temp;
    return count;
}

long Merge(int* data, int start, int mid, int end, int* temp) {
    int s = start;
    int e = end;
    int m = mid;
    int count = 0;
    int index = 0;
    while (m >= start && e > mid) {
        if (data[m] > data[e]) {
            temp[index++] = data[m--]; 
            count += e - mid;
        } else {
            temp[index++] = data[e--]; 
        }
    }
    while (m >= start) {
        temp[index++] = data[m--]; 
    }
    while (e > mid) {
        temp[index++] = data[e--]; 
    }


    for (int i = 0; i < index; i++) {
        data[end - i] = temp[i];
    }
    return count;
}

long InversePairs_5_core(int* data, int start, int end, int* temp) {
    long inversePairs = 0;
    if (start < end) {
        int mid = (start + end) / 2;
        inversePairs += InversePairs_5_core(data, start, mid, temp);
        inversePairs += InversePairs_5_core(data, mid + 1, end, temp);
        inversePairs += Merge(data, start, mid, end, temp);
    }
    return inversePairs;
}

long InversePairs_5(vector<int> data) {
    int* temp = new int[data.size()];
    int* array = new int[data.size()];
    for (int i = 0; i < data.size(); i++) {
        array[i] = data[i];
    }
    int count = InversePairsCore(array, 0, data.size() - 1, temp); 
    delete[] temp;
    delete[] array;
    return count;
}

typedef long (*Fun)(vector<int>);

int main(int argc, char** argv) {
    int count;
    int range;
    if (argc == 1) {
        count = 10;
        range = 10;
    } else if ( argc == 2) {
        count = atoi(*(argv + 1));
        range = 10;
    } else {
        count = atoi(*(argv + 1));
        range = atoi(*(argv + 2));
    }
    //int array[] = {7, 1, 3, 4, 5 };
    vector<int> data = createData(count, range);
    //printVector_int(data); 
    //vector<int> data(array, array + sizeof(array) / sizeof(int));
    list<Fun> funList;
    //funList.push_back(InversePairs_1);
    funList.push_back(InversePairs_2);
    funList.push_back(InversePairs_5);
    list<Fun>::iterator begin = funList.begin();
    while (begin != funList.end()) {
    cout << "------------------------------------------" << endl;
    long lastTime = getTime();
    long P = (**begin++)(data);
    cout << "spent time : " << getTime() - lastTime << endl;
    cout << "inverse pairs is " << P << endl;
    }
}
