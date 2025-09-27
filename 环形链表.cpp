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
//    bool hasCycle(ListNode* head) {
//        if (!head) return false;
//        ListNode* slow = head, * fast = head;
//        while (fast && fast->next) {
//            slow = slow->next;
//            fast = fast->next->next;
//            if (slow == fast) return true;
//		}   
//		return false;
//    }
//};
//
//int main() {
//    Solution solution;
//    // Creating a linked list with a cycle for testing: 3 -> 2 -> 0 -> -4
//    ListNode* head = new ListNode(3);
//    head->next = new ListNode(2);
//    head->next->next = new ListNode(0);
//    head->next->next->next = new ListNode(-4);
//    head->next->next->next->next = head->next; // Creating a cycle here
//    bool result = solution.hasCycle(head);
//    cout << "Has cycle: " << (result ? "true" : "false") << endl; // Output: true
//    // Clean up memory (not shown here for brevity)
//    return 0;
//}