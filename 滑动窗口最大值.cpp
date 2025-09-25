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
//			//���ֵ�����������Ϊ��С��ֵ�����Ϊ�������ֵ
//            while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
//            dq.push_back(i);
//			//��֤���ڴ�СΪk
//            if (i - k + 1 < 0) continue;
//			//��֤˫�˶��е�ͷ��Ԫ���ڴ����ڣ�ʱЧ��
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
