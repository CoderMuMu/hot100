//#include <iostream>
//#include <vector>
//using namespace std;
//
//
//class Solution {
//public:
//    int firstMissingPositive(vector<int>& nums) {
//        int n = nums.size();
//        for (int i = 0; i < n; i++) {
//			//[1,n]��Ԫ��û��������ȷ��λ����
//			//nums[i]Ӧ����Ӧi + 1��λ�ã���i = nums[i] - 1��Ϊ�˷�ֹ�ظ�Ԫ�أ���ѭ������ҪǶ��һ��
//            while (nums[i] >= 1 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
//				int j = nums[i] - 1;
//				swap(nums[i], nums[j]);
//            }
//        }
//        for (int i = 0; i < n; i++) {
//			if (nums[i] != i + 1) return i + 1;
//        }
//		return n + 1;
//    }
//};
//
//int main() {
//    Solution solution;
//    vector<int> nums = {3,4,-1,1};
//    int result = solution.firstMissingPositive(nums);
//    cout << "First missing positive: " << result << endl; // Output: 2
//    return 0;
//}