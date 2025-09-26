//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Solution {
//public:
//    int maxSubArray(vector<int>& nums) {
//        int n = nums.size();
//        int maxSum = nums[0];
//        vector<int> dp(n);
//        for (int i = 0; i < n; i++) dp[i] = nums[i];
//        for (int i = 1; i < n; i++) {
//            dp[i] = max(dp[i], dp[i - 1] + nums[i]);
//            maxSum = max(maxSum, dp[i]);
//        }
//        return maxSum;
//    }
//};
//
//int main() {
//    Solution solution;
//    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
//    int result = solution.maxSubArray(nums);
//    cout << "Maximum subarray sum: " << result << endl; // Output: 6
//    return 0;
//}