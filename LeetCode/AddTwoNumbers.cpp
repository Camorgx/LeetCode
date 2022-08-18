// https://leetcode.cn/problems/add-two-numbers/
#include <vector>
#include <iostream>

namespace AddTwoNumbers {
	using std::vector;
	using std::cout, std::endl;

	struct ListNode {
		int val;
		ListNode* next;
		ListNode() : val(0), next(nullptr) {}
		ListNode(int x) : val(x), next(nullptr) {}
		ListNode(int x, ListNode* next) : val(x), next(next) {}
	};

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

	class Solution {
	public:
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
			ListNode* head = new ListNode;
			ListNode* p = head, * prev = nullptr;
			while (l1 || l2) {
				if (!p) p = new ListNode;
				if (prev) prev->next = p;
				if (l1) p->val += l1->val;
				if (l2) p->val += l2->val;
				if (p->val >= 10) {
					p->val -= 10;
					p->next = new ListNode(1);
				}
				prev = p;
				p = p->next;
				if (l1) l1 = l1->next;
				if (l2) l2 = l2->next;
			}
			return head;
		}
	};

	void run_test() {
		Solution solution;
		vector<vector<int>> l1 = {
			{2, 4, 3},
			{0},
			{9, 9, 9, 9, 9, 9, 9}
		};
		vector<vector<int>> l2 = {
			{5, 6, 4},
			{0},
			{9, 9, 9, 9}
		};
		for (int i = 0; i < 3; ++i) {
			ListNode* a = generate_list(l1[i]);
			ListNode* b = generate_list(l2[i]);
			ListNode* c = solution.addTwoNumbers(a, b);
			display_list(c);
			destroy_list(a);
			destroy_list(b);
			destroy_list(c);
		}
	}
}