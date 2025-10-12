#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size(),cnt_max = INT_MIN;
        vector<int> ans;
        unordered_map<int,int> cnt;
        for (int &x:nums) {
            cnt[x]++;
            cnt_max = max(cnt_max,cnt[x]);
        }
        vector<vector<int>> bucket(cnt_max + 1);
        for (auto &[x,y] : cnt){
            bucket[y].push_back(x);
        }
        for (int i = cnt_max;i >= 0 && k > 0;i--) {
            for (auto &x:bucket[i]){
                if (k == 0) break;
                ans.emplace_back(x);
                k--;
            }
        }

        return ans;
    }
};

int main() {
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    Solution st;
    vector<int> ans = st.topKFrequent(nums, k);
    for (int &x:ans) cout << x << " ";

    return 0;
}
