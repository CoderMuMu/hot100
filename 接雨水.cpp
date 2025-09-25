//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Solution {
//public:
//	int trap(vector<int>& height) {
//		int n = height.size();
//		int ans = 0;
//		int pre_max = 0, suf_max = 0;
//		int left = 0, right = n - 1;
//		while (left <= right) {
//			pre_max = max(pre_max, height[left]);
//			suf_max = max(suf_max, height[right]);
//			if (pre_max < suf_max) {
//				ans += pre_max - height[left++];
//			}
//			else {
//				ans += suf_max - height[right--];
//			}
//		}
//		return ans;
//	}
//};
//
//int main() {
//	Solution solution;
//	vector<int> height = { 0,1,0,2,1,0,1,3,2,1,2,1 };
//	int result = solution.trap(height);
//	cout << result << endl; // Output: 6
//	return 0;
//}