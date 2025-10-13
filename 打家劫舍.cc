#include <functional>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1);
        vector<int> cache(n + 1,-1);
        function<int(int)> dfs = [&](int i)->int{
            if (i < 0) {
                return 0;
            }
            if (cache[i] != -1) return cache[i];
            int res = max(dfs(i - 1),dfs(i - 2) + nums[i]);
            cache[i] = res;
            return res;
        };
        return dfs(n - 1);
    }
};

int main() {
    vector<int> nums = {1,2,3,1};
    cout << Solution().rob(nums) << endl;

    return 0;
}

