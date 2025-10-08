#include <functional>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> path;
        // dfs(i) 表示的是选择第i个数
        function<void(int)> dfs = [&](int i)->void{
            if (i == n) {
                ans.emplace_back(path);
                return;
            }

            // 不选
            dfs(i + 1);
            
            // 选
            path.emplace_back(nums[i]);
            dfs(i + 1);
            path.pop_back();
        };
        dfs(0);
        return ans;
    }
};


int main() {

    vector<int> nums = {1,2,3};
    Solution sl;
    auto ans = sl.subsets(nums);
    for (auto &a:ans) {
        for (int &x:a) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}

