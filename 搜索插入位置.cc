#include <iostream>
#include <vector>
#include <functional>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        function<int(int,int)> lower_bound = [&](int left,int right)->int{
            while (left + 1 < right) {
                int mid = left + (right - left) / 2;
                if (nums[mid] < target) {
                    left++;
                }else{
                    right--;
                }
            }
            return right;
        };
        return lower_bound(-1,n);
    }
};

int main() {

    vector<int> nums = {1,3,5,6};
    int target = 5;
    Solution sl;
    cout << sl.searchInsert(nums,target) << endl;

    return 0;
}
