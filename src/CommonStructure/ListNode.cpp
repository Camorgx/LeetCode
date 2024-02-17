#include "Common/ListNode.h"

#include <iostream>

using std::cout, std::endl;
using std::vector;

ListNode* generateList(const std::vector<int>& data) {
    auto* head = new ListNode(data[0]);
    ListNode* p = head;
    for (auto i = data.begin() + 1; i != data.end(); ++i) {
        p->next = new ListNode(*i);
        p = p->next;
    }
    return head;
}

void displayList(ListNode* head) {
    while (head) {
        cout << head->val;
        head = head->next;
    }
    cout << endl;
}

void destructList(ListNode* head) {
    while (head) {
        ListNode* p = head;
        head = head->next;
        delete p;
    }
}
