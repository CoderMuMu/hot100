#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        // ranges::next_premutation(nums);
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        if (i >= 0) {
            int j = n - 1;
            while (nums[j] <= nums[i]){
                j--;
            }
            swap(nums[j],nums[i]);
        }
        reverse(nums.begin() + i + 1,nums.end());
    }
};

int main() {

    vector<int> nums = {1,2,3};
    Solution().nextPermutation(nums);
    for (int &x:nums) cout << x << " ";

    return 0;
}