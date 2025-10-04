#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode (int x) :val(x),left(nullptr),right(nullptr){}
};

// class Solution {
// public:
//     bool isValidBST(TreeNode* root,long long left = LLONG_MIN,long long right = LLONG_MAX) {
//         if (!root) {
//             return true;
//         }
//         long long x = root->val;
//         if (x <= left || x >= right) {
//             return false;
//         }
        
//         return isValidBST(root->left,left,x) && isValidBST(root->right,x,right);
//     }
// };

class Solution {
public:
    long long pre = LLONG_MIN;
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        if (!isValidBST(root->left)) {
            return false;
        }
        if (root->val <= pre) {
            return false;
        }
        pre = root->val;
        return isValidBST(root->right);
    }
};


int main() {
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    Solution sl;
    cout << sl.isValidBST(root) << endl;
}

