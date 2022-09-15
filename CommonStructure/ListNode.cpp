#include "ListNode.h"

#include <iostream>

using std::vector;
using std::cout, std::endl;

ListNode* generate_list(const vector<int>& data) {
	ListNode* head = new ListNode(data[0]);
	ListNode* p = head;
	for (auto i = data.begin() + 1; i != data.end(); ++i) {
		p->next = new ListNode(*i);
		p = p->next;
	}
	return head;
}

void display_list(ListNode* head) {
	while (head) {
		cout << head->val;
		head = head->next;
	}
	cout << endl;
}

void destroy_list(ListNode* head) {
	while (head) {
		ListNode* p = head;
		head = head->next;
		delete p;
	}
}