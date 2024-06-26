// https://leetcode.cn/problems/add-two-numbers/
#include "Common.h"

namespace AddTwoNumbers {
    using std::vector;

    class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            auto* head = new ListNode;
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

    void runTest() {
        Solution solution;
        vector<vector<int>> l1 = {
            {2, 4, 3},
            {0},
            {9, 9, 9, 9, 9, 9, 9}};
        vector<vector<int>> l2 = {
            {5, 6, 4},
            {0},
            {9, 9, 9, 9}};
        for (int i = 0; i < 3; ++i) {
            ListNode* a = generateList(l1[i]);
            ListNode* b = generateList(l2[i]);
            ListNode* c = solution.addTwoNumbers(a, b);
            displayList(c);
            destructList(a);
            destructList(b);
            destructList(c);
        }
    }
}// namespace AddTwoNumbers