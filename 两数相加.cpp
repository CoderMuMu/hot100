//#include <iostream>
//using namespace std;
//
//struct ListNode {
//    int val;
//    ListNode* next;
//    ListNode(int x) : val(x), next(NULL) {}
//};
//
//class Solution {
//public:
//    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//        ListNode *cur = new ListNode(0);
//        ListNode *head = cur;
//        int carry = 0;
//        while (l1 || l2 || carry) {
//            if (l1) {
//                carry += l1->val;
//                l1 = l1->next;
//            }
//            if(l2) {
//                carry += l2->val;
//                l2 = l2->next;
//            }
//            cur->next = new ListNode(carry % 10);
//            carry /= 10;
//            cur = cur->next;
//        }
//        ListNode *ans = head->next;
//        delete head;
//        return ans;
//    }
//};
//
//int main() {
//    Solution solution;
//    ListNode* l1 = new ListNode(2);
//    l1->next = new ListNode(4);
//    l1->next->next = new ListNode(3);
//    ListNode* l2 = new ListNode(5);
//    l2->next = new ListNode(6);
//    l2->next->next = new ListNode(4);
//    ListNode* result = solution.addTwoNumbers(l1, l2);
//    while (result) {
//        cout << result->val << " ";
//        result = result->next;
//    }
//    return 0;
//}
//
