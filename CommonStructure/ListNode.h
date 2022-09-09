#pragma once

#include <vector>

// LeetCode ͨ������ڵ�
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

extern ListNode* generate_list(const std::vector<int>& data);

extern void display_list(ListNode* head);

extern void destroy_list(ListNode* head);
