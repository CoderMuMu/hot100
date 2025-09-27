//#include <iostream>
//using namespace std;
//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};
//
//class Solution {
//public:
//    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
//		ListNode* p = headA, * q = headB;
//        while (p != q) {
//			p = p ? p->next : headB;
//			q = q ? q->next : headA;
//        }
//        return p;
//    }
//};
//
//int main() {
//    Solution solution;
//    // Creating intersecting linked lists for testing
//    ListNode* common = new ListNode(8);
//    common->next = new ListNode(4);
//    common->next->next = new ListNode(5);
//    ListNode* headA = new ListNode(4);
//    headA->next = new ListNode(1);
//    headA->next->next = common;
//    ListNode* headB = new ListNode(5);
//    headB->next = new ListNode(0);
//    headB->next->next = new ListNode(1);
//    headB->next->next->next = common;
//    ListNode* intersection = solution.getIntersectionNode(headA, headB);
//    if (intersection) {
//        cout << "Intersection at node with value: " << intersection->val << endl; // Output: 8
//    } else {
//        cout << "No intersection." << endl;
//    }
//    // Clean up memory (not shown here for brevity)
//    return 0;
//}