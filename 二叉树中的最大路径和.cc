#include <cstdint>
#include <functional>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;// 注意节点值有可能是负数，所以这里取最小
        function<int(TreeNode *)> dfs = [&](TreeNode *node)->int {
            if (node == nullptr) {
                return 0;
            }
            int left_val = dfs(node->left);
            int right_val = dfs(node->right);
            sum = max(sum,left_val + right_val + node->val);
            // 当左右子树贡献都是负数的时候，更好的选择是 0
            return max(max(left_val,right_val) + node->val,0);
        };
        dfs(root);
        return sum;
    }
};

int main() {

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    Solution sl;
    TreeNode *root1 = new TreeNode(-3);
    cout << sl.maxPathSum(root1) << endl;

    return 0;
}