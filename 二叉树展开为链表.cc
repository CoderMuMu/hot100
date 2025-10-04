#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode (int x):val(x),left(nullptr),right(nullptr){};
};

class Solution {
    TreeNode *head;
public:
    void flatten(TreeNode* root) {
        if(!root) {
            return;
        }
        flatten(root->right);
        flatten(root->left);
        root->right = head;
        root->left = nullptr;
        head = root;
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);
    Solution sl;
    sl.flatten(root);
    while (root->right) {
        cout << root->val << " ";
        root = root->right;
    }
    return 0;
}