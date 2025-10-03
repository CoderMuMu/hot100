#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){};
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> vals;
            for (int i = q.size();i > 0;i--) {
                auto node = q.front();
                vals.push_back(node->val);
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right); 
            }
            ans.push_back(vals);
        }
        return ans;
    }
};

int main() {

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    vector<vector<int>> ans;
    Solution sl;
    ans = sl.levelOrder(root);
    for (auto vec:ans) {
        for (int x:vec) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}