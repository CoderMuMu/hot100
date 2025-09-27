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
//    ListNode* reverseList(ListNode* head) {
//        ListNode* prev = NULL, *curr = head;
//        while (curr) {
//            ListNode* nxt = curr->next;
//            curr->next = prev;
//            prev = curr;
//            curr = nxt;
//        }
//        return prev;
//    }
//    ListNode* middleNode(ListNode* head) {
//        ListNode* slow = head, * fast = head;
//        while (fast && fast->next) {
//            slow = slow->next;
//			fast = fast->next->next;
//        }
//        return slow;
//    }
//
//    bool isPalindrome(ListNode* head) {
//        ListNode* head1 = middleNode(head);
//        ListNode* head2 = reverseList(head1);
//        ListNode* p1 = head, * p2 = head2;
//        while (p2) {
//            if (p1->val != p2->val) {
//                return false;
//            }
//			p1 = p1->next;
//			p2 = p2->next;
//        }
//        return true;
//    }
//};
//
//int main() {
//    Solution solution;
//    // Creating a linked list for testing: 1 -> 2 -> 2 -> 1
//    ListNode* head = new ListNode(1);
//    head->next = new ListNode(2);
//    head->next->next = new ListNode(2);
//    head->next->next->next = new ListNode(1);
//    bool result = solution.isPalindrome(head);
//    cout << "Is palindrome: " << (result ? "true" : "false") << endl; // Output: true
//    // Clean up memory (not shown here for brevity)
//    return 0;
//}