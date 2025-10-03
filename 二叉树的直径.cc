#include <iostream>
using namespace std;


struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x),left(nullptr),right(nullptr){};
};

/*
    二叉树的直径就是任意两个结点之间最长路径的长度，对于一棵树来说
    他的直径 = 左子树最长链的长度 + 右子树最长链的长度 + 2
    那么对于某个子树的最长链的长度 = max(左子树的最长链的长度，右子树的最长链的长度) + 1
*/

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        auto dfs = [&](this auto&& dfs,TreeNode *node)->int {
            if (node == nullptr) {
                return -1;
            }
            int l_max_length = dfs(node->left);
            int r_max_length = dfs(node->right);
            ans = max(ans, l_max_length + r_max_length + 2);

            return max(l_max_length,r_max_length) + 1;
        };
        dfs(root);
        return ans;
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    Solution sl;
    cout << sl.diameterOfBinaryTree(root) << endl;
    return 0;
}