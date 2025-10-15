#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> imax(nums.begin(),nums.end()),imin(nums.begin(),nums.end());
        for (int i = 1;i < n;i++) {
            if (nums[i] > 0) {
                imax[i] = max(imax[i - 1] * nums[i],nums[i]);
                imin[i] = min(imin[i - 1] * nums[i],nums[i]);
            }else{
                imax[i] = max(imin[i - 1] * nums[i],nums[i]);
                imin[i] = min(imax[i - 1] * nums[i],nums[i]);
            }
        }
        return *max_element(imax.begin(),imax.end());
    }
};

int main() {

    vector<int> nums = {2,3,-2,4};
    cout << Solution().maxProduct(nums) << endl;
    return 0;
}