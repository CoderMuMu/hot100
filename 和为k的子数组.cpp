//#include <iostream>
//#include <vector>
//#include <unordered_map>
//using namespace std;
//
//class Solution {
//public:
//    int subarraySum(vector<int>& nums, int k) {
//        int n = nums.size();
//		unordered_map<int, int> countMap; 
//        vector<int> prefixSums(n + 1, 0);
//        for (int i = 0; i < n; i++) {
//            prefixSums[i + 1] = prefixSums[i] + nums[i];
//        }
//        // prefixSums[j] - prefixSums[i] = k  => prefixSums[i] = prefixSums[j] - k
//        int ans = 0;
//        for (int& x : prefixSums) {
//            if (countMap.count(x - k)) {
//                ans += countMap[x - k];
//            }
//            countMap[x]++;
//        }
//        return ans;
//    }
//};
//
//int main() {
//    Solution solution;
//    vector<int> nums = {1,1,1};
//    int k = 2;
//    cout << solution.subarraySum(nums, k) << endl; // Output: 2
//    return 0;
//}