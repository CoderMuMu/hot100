#include <functional>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        function<int(int)> lower_bound = [&](int target)->int{
            int left = -1,right = n;
            while (left + 1 < right){
                int mid = left + (right - left) / 2;
                if (nums[mid] < target) {
                    left = mid;
                }else{
                    right = mid;
                } 
            }
            return right;
        };
        int start = lower_bound(target);
        if (start == n || nums[start] != target) { // 说明nums中没有target
            return {-1,-1};
        }
        int end = lower_bound(target + 1) - 1;// index(>= x + 1 )- 1
        return {start,end};
    }
};

int main() {
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    Solution sl;
    auto ans = sl.searchRange(nums, target);
    for (int &x:ans){
        cout << x << " ";
    }
    return 0;
}