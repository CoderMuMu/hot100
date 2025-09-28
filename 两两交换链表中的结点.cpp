#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) :val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *dummy = new ListNode (0);
        dummy->next = head;
        ListNode *h0 = dummy;
        ListNode *h1 = head;
        while (h1 && h1->next) {
            ListNode *h2 = h1->next;
            ListNode *h3 = h2->next;

            h0->next = h2;
            h1->next = h3;
            h2->next = h1;

            h0 = h1;
            h1 = h3;
        }
        ListNode *ans = dummy->next;
        delete dummy;
        return ans;
    }
};

int main() {
    Solution solution;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    ListNode *result = solution.swapPairs(head);
    while (result) {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}