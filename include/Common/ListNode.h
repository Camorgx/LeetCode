#pragma once

#include <vector>

// LeetCode 通用链表节点
struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}

    explicit ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

extern ListNode* generateList(const std::vector<int>& data);

extern void displayList(ListNode* head);

extern void destructList(ListNode* head);
