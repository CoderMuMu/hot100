//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Solution {
//public:
//    int maxArea(vector<int>& height) {
//        int left = 0,right = height.size() - 1;
//        int ans = 0;
//        while (left < right) {
//            int k = min(height[right], height[left]);
//            int c = right - left;
//            ans = max(ans, c * k);
//            if (height[left] < height[right]) {
//                left++;
//            }
//            else {
//                right--;
//            }
//        }
//		return ans;
//    }
//};
//
//
//int main() {
//    Solution solution;
//    vector<int> height = {1,8,6,2,5,4,8,3,7};
//    int result = solution.maxArea(height);
//    cout << result << endl; // Output: 49
//}