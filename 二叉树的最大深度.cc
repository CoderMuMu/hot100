#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) :val(val),left(nullptr),right(nullptr){}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        int l_length = maxDepth(root->left);
        int r_length = maxDepth(root->right);
        return max(l_length,r_length) + 1;
    }
};

int main() {
    Solution sl;
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    cout << sl.maxDepth(root) << endl;
    return 0;
}