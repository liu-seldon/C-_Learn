#include <iostream>
using namespace std;

class Child {
    public:
    Child():next(NULL), position(0) {}
    Child(int pos) : next(NULL), pre(NULL), position(pos) {}
    Child* next;
    Child* pre;
    int position;
};

void printQueue(Child* head) {
    Child *temp = head;
    do {
        if(temp) {
            cout << temp->position << " " ;
            temp = temp->next;
        } else {
            cout << "The queue ends" << endl;
        }
    } while (temp != head);
    cout << endl;
}

int LastRemaining_Solution(unsigned int n, unsigned int m)
{
    int  count = n;
    Child*  firstChild = new Child(0);
    Child* head = firstChild;
    for (int i = 1; i < count; i++) {
        Child* temp = new Child(i);
        head->next = temp;
        temp->pre = head;
        head = head->next;
    }
    head->next = firstChild;
    firstChild->pre = head;
    head = firstChild;
    printQueue(head);
    int num = 0;
    while (count > 1) {
        if(head->next != head) {
            head=head->next;
            num++;
            if(num == m) {
                head->pre->next = head->next;
                head->next->pre = head->pre;
                cout << "remove number is " << head->position << endl;
                Child * temp = head;
                head= head->next;
                delete temp;
                num = 0;
                count--;
            }
        } else {
            cout << "head next == pre, return" << endl;
            break;
        }
    }
    return head->position;
}


int LastRemaining(int m, int n) {
    int* childs = new int[m];
    int *child = childs;
    for (int i = 0; i < m; i++) {
        childs[i] = 1;
    }

    for (int i = 0; i < m; i++) {
        cout << i << " ";
    }
    cout << endl;
    int count = m;
    int num = 0;
    int index = 0;
    while (count > 1) {
        if (childs[index % m]) {
            num++;
            if (num == n) {
              childs[index % m] = 0; 
              cout << "remove " << index % m << endl;
              num = 0;
              count--;
            }
        } 
        index++;
    }
    int pos = -1;
    for (int i = 0; i < m; i++) {
        if (childs[i]) {
             pos = i;
        }
    }
    return pos;
}
int main() {
    int childCount, numberM;
    while(!cin.fail()) {
        cin >> childCount >> numberM;
        int lastN = LastRemaining(childCount, numberM);
        cout << "The last number is " << lastN << endl;
    }
}
