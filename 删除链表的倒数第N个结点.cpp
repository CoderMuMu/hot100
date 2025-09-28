#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) :val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *cur = head;
        int len = 0;
        while(cur) {
            cur = cur->next;
            len++;
        }
        len -= n;
        ListNode *slow = dummy;
        while (len > 0) {
            slow = slow->next;
            len--;
        }
        ListNode *toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete;
        return dummy->next;
    }
};

int main() {
    Solution solution;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    ListNode *result = solution.removeNthFromEnd(head, 2);
    while (result) {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}
