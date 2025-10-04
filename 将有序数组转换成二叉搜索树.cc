#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution {
public:
    TreeNode *dfs(vector<int>& nums,int left,int right) {
        if (left == right) {
            return nullptr;
        }
        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = dfs(nums,left,mid);
        root->right = dfs(nums,mid + 1,right);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums,0,nums.size());
    }
};

void print(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty()) {
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

    Solution sl;
    vector<int> nums = {-10,-3,0,5,9};
    TreeNode *root = sl.sortedArrayToBST(nums);
    print(root);

    return 0;
}
