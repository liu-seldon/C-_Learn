#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x):val(x), next(NULL) {}
};

ListNode* Merge(ListNode* pHead1, ListNode* pHead2){
    if (pHead1 == NULL && pHead2 == NULL) {
        return NULL;
    }
    if (pHead1 == NULL) {
        return pHead2;
    }
    if (pHead2 == NULL) {
        return pHead1;
    }
    ListNode*  newHead;
    ListNode* nextList;
    if (pHead1->val > pHead2->val) {
        newHead = pHead2;
        nextList = pHead1;
    } else {
        newHead = pHead1;
        nextList = pHead2;
    }

    ListNode* preNode = NULL, *nextNode = NULL;
    preNode = newHead;
    ListNode* head = newHead;
    bool moveHead1 = false;
    bool moveHead2 = false;
    while (head && nextList) {
        if (head->val <= nextList->val) {
            preNode = head;
            head = head->next;
            continue;
        }
        if (preNode->val)
        preNode->next = nextList;
        nextList = nextList->next;
        preNode = preNode->next;
        preNode->next = head;
    }

    if (!head && nextList) {
        preNode->next = nextList;
    }

    return newHead;
}

void print(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int list1[] = {1,1, 3, 7, 19, 24};
    int list2[] = {2,4, 4, 6, 45};

    ListNode *head1;
    ListNode *head2;
    ListNode h1(1);
    ListNode h2(2);
    head1 = &h1;
    head2 = &h2;
    for(int i = 1; i < sizeof(list1) / sizeof(list1[0]); i++) {
        head1->next = new ListNode(list1[i]);
        head1 = head1->next;
    } 

    for(int i = 1; i < sizeof(list2) / sizeof(list2[0]); i++) {
        head2->next = new ListNode(list2[i]);
        head2 = head2->next;
    } 

    print(&h1);
    print(&h2);
    ListNode* head = Merge(&h1, &h2);
    print(head);
    return 0;

}


