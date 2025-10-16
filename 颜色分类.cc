#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    void sortColors1(vector<int>& nums) {
        int ptr = 0,n = nums.size();
        for (int i = 0;i < n;i++) {
            if (nums[i] == 0){
                swap(nums[ptr],nums[i]);
                ptr++;
            }
        }
        for (int i = 0;i < n;i++) {
            if (nums[i] == 1){
                swap(nums[ptr],nums[i]);
                ptr++;
            }
        }
    }
    void sortColors(vector<int>& nums) {
        int n = nums.size(),left = 0,right = n - 1,i = 0;
        while (i <= right) {
            if (nums[i] == 0) {
                swap(nums[left],nums[i]);
                left++;
                i++;
            }else if (nums[i] == 2) {
                swap(nums[right],nums[i]);
                right--;
            }else{
                i++;
            }
        }
    }
};

int main() {

    vector<int> nums = {2,0,2,1,1,0};
    Solution().sortColors(nums);
    for (int &x:nums) cout << x << " ";
    return 0;
}