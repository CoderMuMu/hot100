#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size(),end = nums.back();
        int left = -1,right = nums.size() - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= end) {
                left = mid;
            }else{
                right = mid;
            }
        }
        return nums[right];
    }
};

int main() {

    vector<int> nums = {3,4,5,1,2};
    Solution st;
    cout << st.findMin(nums) << endl;
    
    return 0;
}