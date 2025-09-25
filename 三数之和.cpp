//#include <iostream>
//#include <vector>
//#include <algorithm>  
//using namespace std;
//
//class Solution {
//public:
//    vector<vector<int>> threeSum(vector<int>& nums) {
//        vector<vector<int>> ans;
//        ranges::sort(nums);
//        int n = nums.size();
//        for (int i = 0; i < nums.size() - 2; i++) {
//            int x = nums[i];
//            if (i >= 1 && x == nums[i - 1]) continue;
//
//            if (x + nums[i + 1] + nums[i + 2] > 0) break;//优化二
//            if (x + nums[n - 2] + nums[n - 1] < 0) continue;//优化一
//            int j = i + 1, k = nums.size() - 1;
//            while (j < k) {
//                int sum = x + nums[j] + nums[k];
//                if (sum == 0) {
//                    ans.push_back({ x,nums[j],nums[k] });
//                    while (j < k && nums[j] == nums[j + 1]) j++;
//                    while (j < k && nums[k] == nums[k - 1]) k--;
//                    //j和k正常移动
//                    j++;
//                    k--;
//                }
//                else if (sum < 0) {
//                    j++;
//                }
//                else {
//                    k--;
//                }
//            }
//        }
//        return ans;
//    }
//};
//
//
//int main() {
//    Solution solution;
//    vector<int> nums = { -1,0,1,2,-1,-4 };
//    vector<vector<int>> result = solution.threeSum(nums);
//    for (const auto& triplet : result) {
//        cout << "[";
//        for (int num : triplet) {
//            cout << num << " ";
//        }
//        cout << "]" << endl;
//    }
//    return 0;
//}
