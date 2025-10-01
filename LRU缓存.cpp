#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    int key;
    int val;
    Node *prev;
    Node *next;

    Node (int k = 0,int v = 0) : key(k),val(v){}
};

class LRUCache {
private:
    int capacity;
    unordered_map<int,Node *> key_to_node;
    Node *dummy;


    void remove(Node *x) {
        x->prev->next = x->next;
        x->next->prev = x->prev;
    }


    void push_front(Node *x) {
        x->prev = dummy;
        x->next = dummy->next;
        x->prev->next = x;
        x->next->prev = x;
    }

    Node *get_node(int key) {
        auto it = key_to_node.find(key);
        if (it == key_to_node.end()) {
            return nullptr;
        }
        Node *node = it->second;
        remove(node);
        push_front(node);
        return node;
    }

public:
    
    LRUCache(int capacity) : capacity(capacity),dummy(new Node()){
        dummy->next = dummy;
        dummy->prev = dummy;
    }
    
    int get(int key) {
        Node *node = get_node(key);
        return node ? node->val : -1;
    }
    
    void put(int key, int value) {
        Node *node = get_node(key);
        if (node) {
            node->val = value;
            return;
        }
        key_to_node[key] = node = new Node(key,value);
        push_front(node);
        if (key_to_node.size() > capacity) {
            Node *back_node = dummy->prev;
            key_to_node.erase(back_node->key);
            remove(back_node);
            delete back_node;
        }
    }
    
    // 打印缓存内容的方法
    void printCache() {
        cout << "缓存内容：";
        Node *current = dummy->next;
        while (current != dummy) {
            cout << "(" << current->key << ":" << current->val << ") ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    // 创建一个容量为2的LRU缓存
    LRUCache cache(2);
    
    cout << "测试1：添加键1，值1" << endl;
    cache.put(1, 1);
    cache.printCache();  // 应显示：(1:1)
    
    cout << "\n测试2：添加键2，值2" << endl;
    cache.put(2, 2);
    cache.printCache();  // 应显示：(2:2) (1:1)
    
    cout << "\n测试3：获取键1的值" << endl;
    cout << "get(1) = " << cache.get(1) << endl;  // 应返回1
    cache.printCache();  // 应显示：(1:1) (2:2)
    
    cout << "\n测试4：添加键3，值3（超出容量，淘汰最久未使用的键2）" << endl;
    cache.put(3, 3);
    cache.printCache();  // 应显示：(3:3) (1:1)
    
    cout << "\n测试5：获取键2的值（已被淘汰）" << endl;
    cout << "get(2) = " << cache.get(2) << endl;  // 应返回-1
    cache.printCache();  // 应显示：(3:3) (1:1)
    
    cout << "\n测试6：添加键1，值100（更新已有键）" << endl;
    cache.put(1, 100);
    cache.printCache();  // 应显示：(1:100) (3:3)
    
    cout << "\n测试7：添加键4，值4（超出容量，淘汰最久未使用的键3）" << endl;
    cache.put(4, 4);
    cache.printCache();  // 应显示：(4:4) (1:100)
    
    cout << "\n测试8：获取键1的值" << endl;
    cout << "get(1) = " << cache.get(1) << endl;  // 应返回100
    cache.printCache();  // 应显示：(1:100) (4:4)
    
    return 0;
}
