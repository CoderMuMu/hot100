#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int _val) : val(_val), next(nullptr) {}
};

class Solution {
public:
    ListNode *mergeTwoList(ListNode *list1, ListNode *list2) {
        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy;
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
        return dummy->next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        if (lists.size() == 1) return lists[0];

        for (int step = 1; step < lists.size(); step *= 2) {
            for (int i = 0; i + step < lists.size(); i += step * 2) {
                lists[i] = mergeTwoList(lists[i], lists[i + step]);
            }
        }
        return lists[0];
    }
};

// 辅助函数：创建链表
ListNode* createList(const vector<int>& nums) {
    ListNode* dummy = new ListNode(0);
    ListNode* cur = dummy;
    for (int num : nums) {
        cur->next = new ListNode(num);
        cur = cur->next;
    }
    return dummy->next;
}

// 辅助函数：打印链表
void printList(ListNode* head) {
    ListNode* cur = head;
    while (cur) {
        cout << cur->val;
        if (cur->next) cout << " -> ";
        cur = cur->next;
    }
    cout << endl;
}

// 辅助函数：释放链表内存
void freeList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // 创建测试用的多个有序链表
    vector<ListNode*> lists;
    lists.push_back(createList({1, 4, 5}));
    lists.push_back(createList({1, 3, 4}));
    lists.push_back(createList({2, 6}));
    lists.push_back(createList({7, 8, 9}));
    
    // 打印原始链表
    cout << "原始链表：" << endl;
    for (int i = 0; i < lists.size(); i++) {
        cout << "链表 " << i + 1 << "：";
        printList(lists[i]);
    }
    
    // 合并K个链表
    Solution solution;
    ListNode* result = solution.mergeKLists(lists);
    
    // 打印合并结果
    cout << "\n合并后的链表：";
    printList(result);
    
    // 释放内存
    freeList(result);
    
    return 0;
}
