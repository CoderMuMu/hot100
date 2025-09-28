// 本题的附图解环形链表II.png


//#include <iostream>
//using namespace std;
//
//struct ListNode {
//	int val;
//	ListNode* next;
//	ListNode(int x) : val(x), next(NULL) {}
//};	
//
//class Solution {
//public:
//	ListNode* detectCycle(ListNode* head) {
//		ListNode* slow = head, * fast = head;
//		while (fast && fast->next) {
//			slow = slow->next;
//			fast = fast->next->next;
//			if (slow == fast) {
//				ListNode* p = head;
//				while (p != slow) {
//					p = p->next;
//					slow = slow->next;
//				}
//				return p;
//			}
//		}
//		return nullptr;
//	}
//};
//
//
//int main() {
//	Solution solution;
//	// Creating a linked list with a cycle for testing: 3 -> 2 -> 0 -> -4
//	ListNode* head = new ListNode(3);
//	head->next = new ListNode(2);
//	head->next->next = new ListNode(0);
//	head->next->next->next = new ListNode(-4);
//	head->next->next->next->next = head->next; // Creating a cycle here
//	ListNode* result = solution.detectCycle(head);
//	if (result) {
//		cout << "Cycle detected at node with value: " << result->val << endl; // Output: 2
//	} else {
//		cout << "No cycle detected." << endl;
//	}
//	// Clean up memory (not shown here for brevity)
//	return 0;

//}
