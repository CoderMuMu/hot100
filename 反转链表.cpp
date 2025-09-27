//#include <iostream>
//using namespace std;
//
//struct ListNode {
//    int val;
//    ListNode* next;
//	ListNode(int x) : val(x), next(NULL) {}
//};
//
//class Solution {
//public:
//    ListNode* reverseList(ListNode* head) {
//		ListNode* prev = NULL;
//        ListNode* curr = head;
//        while (curr) {
//            ListNode* nxt = curr->next;
//			curr->next = prev;
//            prev = curr;
//            curr = nxt;
//        }
//        return prev;
//    }
//};
//
//int main() {
//    Solution solution;
//    // Creating a linked list for testing: 1 -> 2 -> 3 -> 4 -> 5
//    ListNode* head = new ListNode(1);
//    head->next = new ListNode(2);
//    head->next->next = new ListNode(3);
//    head->next->next->next = new ListNode(4);
//    head->next->next->next->next = new ListNode(5);
//    ListNode* reversedHead = solution.reverseList(head);
//    cout << "Reversed linked list: ";
//    ListNode* current = reversedHead;
//    while (current) {
//        cout << current->val << " ";
//        current = current->next;
//    }
//    cout << endl; // Output: 5 4 3 2 1
//    // Clean up memory (not shown here for brevity)
//    return 0;
//}