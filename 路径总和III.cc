#include <functional>   
#include <iostream>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        int ans = 0;
        unordered_map<long long,int> cnt = {{0,1}};
        function<void(TreeNode *,long long)> dfs = [&](TreeNode *node,long long sj)->void {
            if (node == nullptr) {
                return;
            }
            sj += node->val;
            ans += cnt[sj - targetSum];
            cnt[sj]++;
            dfs(node->left,sj);
            dfs(node->right,sj);
            cnt[sj]--;
        };
        dfs(root,0);
        return ans;
    }
};

int main() {
    int targetSum = 8;
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    root->right->right = new TreeNode(11);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->left->right->right = new TreeNode(1);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    Solution sl;
    cout << sl.pathSum(root,targetSum) << endl;
    return 0;
}