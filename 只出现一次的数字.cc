#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /*
        亦或的性质：
        1.任何数与0异或都等于本身
        2.任何数和自身异或都等于0
        3.异或满足交换律和结合律
    */
    int singleNumber(vector<int>& nums) {
        int ans = 0; // 0是异或的恒等元
        for (int &x:nums){
            ans ^= x;
        }
        return ans;
    }
};

int main() {

    vector<int> nums = {2,2,1};
    cout << Solution().singleNumber(nums) << endl;
    return 0;
}