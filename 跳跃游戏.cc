#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(),max_right = 0;
        for (int i = 0;i < n;i++) {
            if (i > max_right) return false; // 检查当前位置是否可达
            max_right = max(max_right,i + nums[i]);
        }
        return true;
    }
};

int main() {
    vector<int> nums = {2,3,1,1,4};
    Solution st;
    cout << st.canJump(nums) << endl;

    return 0;
}