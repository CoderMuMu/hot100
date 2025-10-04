#include <iostream>
#include <vector>
using namespace std;


struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        auto dfs = [&](this auto&& dfs,TreeNode *node,int depth)->void{
            if (!node) {
                return;
            }
            if (depth == ans.size()) {
                ans.push_back(node->val);
            }
            dfs(node->right,depth + 1);
            dfs(node->left,depth + 1);
        };
        dfs(root,0);
        return ans;
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);
    vector<int> res;
    Solution sl;
    res = sl.rightSideView(root);
    for(int x:res) {
        cout << x << " ";
    }

    return 0;
}

