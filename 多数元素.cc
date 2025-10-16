#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int candidate = nums[0];
        int count = 1;
        for (int i =1 ;i < n;i++) {
            if (count == 0) {
                candidate = nums[i];
                count = 1;
            }else{
                count += (candidate == nums[i] ? 1 : -1);
            }
        }
        return candidate;
    }
};

int main() {

    vector<int> nums = {3,2,3};
    cout << Solution().majorityElement(nums) << '\n';

    return 0;
}