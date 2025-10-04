#include <cstddef>
#include <iostream>
#include <ratio>
#include <vector>
#include <algorithm>
#include <ranges>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) {
            return nullptr;
        }
        int left_size = find(inorder.begin(),inorder.end(),preorder[0]) - inorder.begin();
        vector<int> pre1(preorder.begin() + 1,preorder.begin() + 1 + left_size);
        vector<int> pre2(preorder.begin() + 1 + left_size,preorder.end());
        vector<int> in1(inorder.begin(),inorder.begin() + left_size);
        vector<int> in2(inorder.begin() + left_size + 1,inorder.end());
        TreeNode *root = new TreeNode(preorder[0]);
        root->left = buildTree(pre1,in1);
        root->right = buildTree(pre2, in2);
        return root;
    }
};

void print(TreeNode *root) {
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        for (int i = q.size();i > 0;i--) {
            auto node = q.front();
            q.pop();
            cout << node->val << " ";
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
}

int main() {
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    Solution sl;
    TreeNode *root = sl.buildTree(preorder, inorder);
    print(root);
    return 0;
}