#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode (int x) :val(x),next(nullptr){}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || !head->next) return head;
        int n = 0;
        ListNode *cur = head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *p0 = dummy;
        while(cur) {
            n++;
            cur = cur->next;
        }
        while(n >= k) {
            n -= k;
            ListNode *pre = nullptr;
            ListNode *cur = p0->next;
            for (int i = 0;i < k;i++) {
                ListNode *nxt = cur->next;
                cur->next = pre;
                pre = cur;
                cur = nxt;
            }
            ListNode *nxt = p0->next;
            p0->next->next = cur;
            p0->next = pre;
            p0 = nxt;
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
    ListNode *result = solution.reverseKGroup(head, 2);
    while (result) {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}