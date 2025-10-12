#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(),ans = 0,cur_min = prices[0];
        for (int i = 1;i < n;i++) {
            int x = prices[i];
            if (x > cur_min) {
                ans = max(ans,x - cur_min);
            }
            cur_min = min(cur_min,x);
        }

        return ans;
    }
};

int main() {
    vector<int> prices = {7,1,5,3,6,4};
    Solution st;
    cout << st.maxProfit(prices) << endl;

    return 0;
}