//#include <iostream>
//#include <vector>
//using namespace std;
//
////1.O(n)空间复杂度
//
////class Solution {
////public:
////    vector<int> productExceptSelf(vector<int>& nums) {
////		int n = nums.size();
////		vector<int> ans(n),preMul(n),sufMul(n);
////		preMul[0] = 1; sufMul[n - 1] = 1;
////		for (int i = 1; i < n; i++) {
////			preMul[i] = preMul[i - 1] * nums[i - 1];
////		}
////		for (int i = n - 2; i >= 0; i--) {
////			sufMul[i] = sufMul[i + 1] * nums[i + 1];
////		}
////		for (int i = 0; i <= n - 1; i++) {
////			ans[i] = preMul[i] * sufMul[i];
////		}
////		return ans;
////    }
////};
//
////2.O(1)空间复杂度
//
//class Solution {
//public:
//	vector<int> productExceptSelf(vector<int>& nums) {
//		int n = nums.size();
//		vector<int> sufMul(n);
//		int preMul = 1;
//		sufMul[n - 1] = 1;
//
//		for (int i = n - 2; i >= 0;i--) {
//			sufMul[i] = sufMul[i + 1] * nums[i + 1];
//		}
//
//		for (int i = 0; i < n; i++) {
//			sufMul[i] *= preMul;
//			preMul *= nums[i];
//		}
//		return sufMul;
//	}
//};
//int main() {
//	Solution solution;
//	vector<int> nums = {1,2,3,4};
//	vector<int> result = solution.productExceptSelf(nums);
//	cout << "Product array: ";
//	for (int num : result) {
//		cout << num << " ";
//	}
//	cout << endl; // Output: [24,12,8,6]
//	return 0;
//}
//
//
