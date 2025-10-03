#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : val(val),left(nullptr),right(nullptr){};
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        TreeNode *left = invertTree(root->left);
        TreeNode *right = invertTree(root->right);
        root->left = right;
        root->right = left;
        return root;
    }
};

// 打印二叉树的辅助函数
void printTree(TreeNode* root) {
    if (!root) {
        cout << "空树" << endl;
        return;
    }
    
    queue<TreeNode*> q;
    q.push(root);
    
    cout << "翻转后的二叉树（层序遍历）：" << endl;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
            cout << node->val << " ";
            
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        cout << endl;
    }
}


int main() {
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode (3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    cout << "原始二叉树（层序遍历）：" << endl;
    printTree(root);
    
    Solution sl;
    sl.invertTree(root);
    
    cout << endl;
    printTree(root);

    return 0;
}