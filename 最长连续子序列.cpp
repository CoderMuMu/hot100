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
//            }//x是新序列的起点
//            else {
//                int y = x + 1;//直接从起点的下一个数找，所以初始化为x+1
//                while (nums_set.contains(y)) {
//                    y++;
//                }
//                //循环结束时，y-1是最后一个在哈希集合中的数
//                ans = max(ans,y - x);//从x到y-1一共y-x个数
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