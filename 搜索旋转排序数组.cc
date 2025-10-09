#include <functional>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int last = nums.back();
        int left = -1,right = n - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            int x = nums[mid];
            if (target > last && x <= last) {
                right = mid;
            }else if (target <= last && x > last) {
                left = mid;
            }else if (x >= target){
                right = mid;
            }else{
                left = mid;
            }
        }
        return nums[right] == target ? right : -1;
    }
};

int main() {

    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    Solution sl;
    cout << sl.search(nums,target);
    return 0;
}