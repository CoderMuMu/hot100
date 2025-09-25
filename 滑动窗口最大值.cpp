//#include <iostream>
//#include <vector>
//#include <deque>
//using namespace std;
//
//class Solution {
//public:
//    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//		int n = nums.size();
//        deque <int> dq;
//		vector<int> ans;
//        for (int i = 0; i < n; i++) {
//			//保持单调递增，因为较小的值不会成为窗口最大值
//            while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
//            dq.push_back(i);
//			//保证窗口大小为k
//            if (i - k + 1 < 0) continue;
//			//保证双端队列的头部元素在窗口内，时效性
//            if (i - dq.front() + 1 > k) dq.pop_front();
//			ans.push_back(nums[dq.front()]);
//        }
//        return ans;
//    }
//};
//
//int main() {
//    Solution solution;
//    vector<int> nums = {1,3,-1,-3,5,3,6,7};
//    int k = 3;
//    vector<int> ans = solution.maxSlidingWindow(nums, k);
//    for (int x : ans) {
//        cout << x << " ";
//    }
//    cout << endl; // Output: [3,3,5,5,6,7]
//    return 0;
//}
