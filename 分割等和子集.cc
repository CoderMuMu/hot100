#include <functional>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size(),sum = 0;
        
        for (int &x:nums) {
            sum += x;
        }
        if (sum % 2 == 1) return false;
        vector<vector<int>> mem(n,vector<int>(sum / 2 + 1,-1));
        function<bool(int,int)> dfs = [&](int i,int j)->bool{
            if (i < 0) {
                return j == 0 ? true : false;
            }
            int &res = mem[i][j];
            if (res != -1) return res;
            if (j < nums[i]) {
                return res = dfs(i - 1,j);
            }else{
                return res = dfs(i - 1,j) || dfs(i - 1,j - nums[i]);
            }
        };
        return dfs(n - 1,sum / 2);
    }
};

int main() {

    vector<int> nums = {1,5,11,5};
    cout << Solution().canPartition(nums) << endl;

    return 0;
}