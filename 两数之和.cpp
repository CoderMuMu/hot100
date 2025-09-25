//#include <iostream>
//#include <vector>
//#include <unordered_map>
//using namespace std;
//
//
//class Solution {
//public:
//	vector<int> twoSum(vector<int>& nums, int target) {
//		unordered_map<int, int> num_map; // value -> index
//		for (int i = 0; i < nums.size(); ++i) {
//			int complement = target - nums[i];
//			if (num_map.find(complement) != num_map.end()) {
//				return { num_map[complement], i };
//			}
//			num_map[nums[i]] = i;
//		}
//		return {};
//	}
//};
//
//int main() {
//	Solution solution;
//	vector<int> nums = { 2, 7, 11, 15 };
//	int target = 9;
//	vector<int> result = solution.twoSum(nums, target);
//	cout << "[" << result[0] << ", " << result[1] << "]" << endl; // Output: [0, 1]
//	return 0;
//}