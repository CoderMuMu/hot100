#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> path;
        sort(candidates.begin(),candidates.end());
        function<void(int,int)> dfs = [&](int i,int s)->void {
            if (i >= n || s > target) {
                return;
            }
            if (s == target) {
                ans.emplace_back(path);
                return;
            }
            // 如果加上当前元素会超过目标，跳过选择
            if (s + candidates[i] > target) {
                return;
            }

            dfs(i + 1,s);

            path.emplace_back(candidates[i]);
            //s += candidates[i];
            dfs(i,s + candidates[i]);
            path.pop_back();
            //s -= candidates[i];
        };
        dfs(0,0);
        return ans;
    }
};

int main() {
    vector<int> candidates = {2,3,6,7};
    int target = 7;
    Solution sl;
    auto ans = sl.combinationSum(candidates,target);
    for (auto &a:ans) {
        for (int &x:a) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}