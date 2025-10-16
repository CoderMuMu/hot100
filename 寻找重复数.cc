#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size(),slow = 0,fast = 0;
        slow = nums[slow],fast = nums[nums[fast]];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        int head = 0;
        while (slow != head) {
            slow = nums[slow];
            head = nums[head];
        }
        return slow;
    }
};

int main() {

    vector<int> nums = {1,3,4,2,2};
    cout << Solution().findDuplicate(nums) << endl;
    return 0;
}