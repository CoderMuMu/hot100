#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode (int x) : val(x),left(nullptr),right(nullptr){};
};

class Solution {
public:
    bool isSame(TreeNode *p,TreeNode *q) {
        if (!p || !q) {
            return p == q;
        }
        return p->val == q->val && isSame(p->left,q->right) && isSame(p->right,q->left);
    }
    bool isSymmetric(TreeNode* root) {
        return isSame(root->left,root->right);
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    Solution sl;
    cout << sl.isSymmetric(root) << endl;
}