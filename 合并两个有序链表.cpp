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
//    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//        ListNode* cur = new ListNode(0);
//		ListNode* p = cur;
//        while (list1 && list2) {
//            if (list1->val < list2->val) {
//				cur->next = list1;
//				list1 = list1->next;
//            }
//            else {
//				cur->next = list2;
//				list2 = list2->next;
//            }
//			cur = cur->next;
//        }
//        if (list1) {
//			cur->next = list1;
//        }
//        else {
//			cur->next = list2;
//        }
//		return p->next;
//    }
//};
//
//int main() {
//    Solution solution;
//    // Creating two sorted linked lists for testing: 1 -> 2 -> 4 and 1 -> 3 -> 4
//    ListNode* list1 = new ListNode(1);
//    list1->next = new ListNode(2);
//    list1->next->next = new ListNode(4);
//    ListNode* list2 = new ListNode(1);
//    list2->next = new ListNode(3);
//    list2->next->next = new ListNode(4);
//    ListNode* mergedList = solution.mergeTwoLists(list1, list2);
//    cout << "Merged linked list: ";
//    ListNode* current = mergedList;
//    while (current) {
//        cout << current->val << " ";
//        current = current->next;
//    }
//    cout << endl; // Output: 1 1 2 3 4 4
//    // Clean up memory (not shown here for brevity)
//    return 0;
//}