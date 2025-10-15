#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
       int n = nums.size(),ans = -1;
       vector<int> dp(n + 1,1);
       for (int i = 1;i < n;i++) {
            if (nums[i] > nums[i - 1]) {
                dp[i] = max(dp[i - 1] + 1,dp[i]);
            }
            ans = max(ans,dp[i]);
       } 
       return ans;
    }
};

int main() {
    vector<int> nums = {0,1,0,2,1,3,4};
    cout << Solution().lengthOfLIS(nums) << endl;

    return 0;
}