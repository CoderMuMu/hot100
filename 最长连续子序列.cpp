//#include <iostream>
//#include <vector>
//#include <unordered_set>
//using namespace std;
//
//class Solution {
//public:
//    int longestConsecutive(vector<int>& nums) {
//        unordered_set<int> nums_set(nums.begin(),nums.end());
//        int ans = 0;
//        for (int& x : nums) {
//            if (nums_set.contains(x - 1)) {
//                continue;
//            }//x�������е����
//            else {
//                int y = x + 1;//ֱ�Ӵ�������һ�����ң����Գ�ʼ��Ϊx+1
//                while (nums_set.contains(y)) {
//                    y++;
//                }
//                //ѭ������ʱ��y-1�����һ���ڹ�ϣ�����е���
//                ans = max(ans,y - x);//��x��y-1һ��y-x����
//                if (ans * 2 >= nums_set.size()) {
//                    break;
//                }
//            }
//        }
//        return ans;
//    }
//};
//
//int main() {
//	Solution solution;
//	vector<int> nums = { 0,3,7,2,5,8,4,6,0,1 };
//	int result = solution.longestConsecutive(nums);
//	cout << result << endl; // Output: 4
//}