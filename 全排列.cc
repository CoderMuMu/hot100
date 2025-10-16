#include <functional>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        vector<int> path(n,0);
        vector<bool> on_Path(n,false);
        
        function<void(int)> dfs = [&](int i)->void{
            if (i == n) {
                ans.emplace_back(path);
                return;
            }
            for (int j = 0;j < n;j++) {
                if (!on_Path[j]) {
                    path[i] = nums[j];
                    on_Path[j] = true;
                    dfs(i + 1);
                    on_Path[j] = false;
                }
            }
        };
        dfs(0);
        return ans;
    }
};


int main() {

    Solution sl;
    vector<int> nums = {1,2,3};
    auto ans = sl.permute(nums);
    for (auto &a:ans) {
        for (int &x:a) {
            cout << x << " ";
        }       
        cout << endl; 
    }
    return 0;
}