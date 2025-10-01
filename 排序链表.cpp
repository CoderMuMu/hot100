#include <iostream>
using namespace std;

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
    ListNode *splitList(ListNode *head,int size) {
        ListNode *cur = head;
        for (int i = 0;i < size - 1 && cur != nullptr;i++) {
            cur = cur->next;
        }

        if (cur == nullptr || cur->next == nullptr) {
            return nullptr;
        }

        ListNode * next_head = cur->next;
        cur->next = nullptr;
        return next_head;
    }

    pair<ListNode *,ListNode *> mergeTwoLists(ListNode *list1,ListNode *list2) {
        ListNode dummy;
        ListNode *cur = &dummy;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                cur->next = list1;
                list1 = list1->next;
            }else{
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }
        cur->next = list1 ? list1 : list2;
        while (cur && cur->next) {
            cur = cur->next;
        }
        return {dummy.next,cur};
    }


    ListNode* sortList(ListNode* head) {
        int length = getListLength(head);
        ListNode dummy(0,head);
        for (int step = 1;step < length;step *= 2) {
            ListNode *new_list_tail = &dummy;
            ListNode *cur = dummy.next;
            while (cur) {
                ListNode *head1 = cur;
                ListNode *head2 = splitList(head1,step);
                cur = splitList(head2,step);
                auto [head,tail] = mergeTwoLists(head1,head2);
                new_list_tail->next = head;
                new_list_tail = tail;
            }
        }
        return dummy.next;
    }
};

// 辅助函数：创建链表
ListNode* createList(int arr[], int n) {
    if (n == 0) return nullptr;
    ListNode *head = new ListNode(arr[0]);
    ListNode *cur = head;
    for (int i = 1; i < n; i++) {
        cur->next = new ListNode(arr[i]);
        cur = cur->next;
    }
    return head;
}

// 辅助函数：打印链表
void printList(ListNode *head) {
    ListNode *cur = head;
    while (cur) {
        cout << cur->val << " -> ";
        cur = cur->next;
    }
    cout << "nullptr" << endl;
}

// 辅助函数：释放链表内存
void freeList(ListNode *head) {
    ListNode *cur = head;
    while (cur) {
        ListNode *temp = cur;
        cur = cur->next;
        delete temp;
    }
}

int main() {
    // 测试用例：创建一个未排序的链表
    int arr[] = {4, 2, 1, 3, 5, 9, 7, 8, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    ListNode *head = createList(arr, n);
    
    cout << "排序前的链表：" << endl;
    printList(head);
    
    // 进行排序
    Solution solution;
    ListNode *sortedHead = solution.sortList(head);
    
    cout << "排序后的链表：" << endl;
    printList(sortedHead);
    
    // 释放内存
    freeList(sortedHead);
    
    return 0;
}
