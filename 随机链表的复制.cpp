#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val, Node* _next = nullptr, Node* _random = nullptr) {
        val = _val;
        next = _next;
        random = _random;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head || !head->next) return head;
        //先复制val和next，再复制random，因为同时复制的话，某个结点random指向的可能还没有被建立
        for (Node *cur = head;cur;cur = cur->next->next) {
            cur->next = new Node (cur->val,cur->next,nullptr);
        }
        //复制random，副本的random就是源节点的random的下一个结点
        for (Node *cur = head;cur;cur = cur->next->next) {
            if (cur->random) {
                cur->next->random = cur->random->next;
            }
        }
        Node *new_head = head->next;
        Node *cur = head;
        for (;cur->next->next;cur = cur->next) {
            Node *copy = cur->next;
            cur->next = copy->next;
            copy->next = copy->next->next;
        }
        cur->next = nullptr;
        return new_head;
    }
};
// 辅助函数：打印链表信息（值和随机指针指向的值）
void printList(Node* head) {
    Node* cur = head;
    while (cur) {
        cout << "节点值: " << cur->val;
        if (cur->random) {
            cout << ", 随机指向: " << cur->random->val;
        } else {
            cout << ", 随机指向: null";
        }
        cout << endl;
        cur = cur->next;
    }
}

// 辅助函数：创建测试链表
Node* createTestList() {
    // 创建节点
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    
    // 设置next指针
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = nullptr;
    
    // 设置random指针
    node1->random = node3;  // 1->3
    node2->random = node1;  // 2->1
    node3->random = node4;  // 3->4
    node4->random = node2;  // 4->2
    
    return node1;
}

// 检查两个链表是否结构相同（值和随机指针关系）
bool checkLists(Node* original, Node* copied) {
    // 检查节点值和next关系
    Node* o = original;
    Node* c = copied;
    while (o && c) {
        if (o->val != c->val) return false;
        
        // 检查随机指针指向的节点值是否一致
        if ((o->random == nullptr && c->random != nullptr) || 
            (o->random != nullptr && c->random == nullptr)) {
            return false;
        }
        
        if (o->random && c->random && o->random->val != c->random->val) {
            return false;
        }
        
        o = o->next;
        c = c->next;
    }
    
    // 两个链表长度必须相同
    return o == nullptr && c == nullptr;
}

int main() {
    // 创建测试链表
    Node* head = createTestList();
    
    cout << "原链表内容：" << endl;
    printList(head);
    
    // 复制链表
    Solution solution;
    Node* copiedHead = solution.copyRandomList(head);
    
    cout << "\n复制后的链表内容：" << endl;
    printList(copiedHead);
    
    // 验证复制结果
    bool isSame = checkLists(head, copiedHead);
    if (isSame) {
        cout << "\n测试结果：复制成功，结构与原链表一致！" << endl;
    } else {
        cout << "\n测试结果：复制失败，与原链表结构不一致！" << endl;
    }
    
    // 验证是否是深拷贝（不是同一个对象）
    if (head && copiedHead && head != copiedHead) {
        cout << "验证：确实是深拷贝，不是原链表本身！" << endl;
    }
    
    return 0;
}

