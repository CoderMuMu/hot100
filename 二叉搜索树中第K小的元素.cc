#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution {
public:
    
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        auto dfs = [&](this auto&& dfs,TreeNode *node)->void {
            if (node == nullptr || k == 0) {
                return;
            }
            dfs(node->left);
            if (--k == 0) {
                ans = node->val;
            }
            dfs(node->right);
        };
        dfs(root);
        return ans;
    }
};

int main() {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    Solution sl;
    cout << sl.kthSmallest(root,1);
}
