#include <iostream>
using namespace std;

// 链表节点定义
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int getListLength(ListNode *head) {
        int n = 0;
        ListNode *cur = head;
        while (cur) {
            n++;
            cur = cur->next;
        }
        return n;
    }

    ListNode *splitList(ListNode *head, int size) {
        ListNode *cur = head;
        for (int i = 0; i < size - 1 && cur; i++) {
            cur = cur->next;
        }
        if (!cur) {
            return nullptr;
        }
        ListNode *next_list_head = cur->next;
        cur->next = nullptr;
        return next_list_head;
    }

    pair<ListNode *, ListNode *> mergeList(ListNode *list1, ListNode *list2) {
        ListNode dummy(0);
        ListNode *cur = &dummy;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                cur->next = list1;
                list1 = list1->next;
            } else {
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }
        cur->next = list1 ? list1 : list2;
        while (cur->next) {
            cur = cur->next;
        }
        return {dummy.next, cur};
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        int length = getListLength(head);
        ListNode dummy(0);
        dummy.next = head;

        for (int size = 1; size < length; size *= 2) {
            ListNode *prev = &dummy;
            ListNode *cur = dummy.next;
            while (cur) {
                ListNode *head1 = cur;
                ListNode *head2 = splitList(head1, size);
                cur = splitList(head2, size);
                
                auto [mergedHead, mergedTail] = mergeList(head1, head2);
                prev->next = mergedHead;
                prev = mergedTail;
            }
        }
        return dummy.next;
    }
};

int main () {
    ListNode *head = new ListNode (4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);
    Solution sl;
    ListNode *result = sl.sortList(head);
    while (result) {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}
    