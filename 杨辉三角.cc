#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> dp(numRows);
        for (int i = 0;i < numRows;i++) {
            dp[i].resize(i + 1); // 给第i行分配i+1个空间
            dp[i][0] = 1;
            dp[i][i] = 1;
            if (i <= 1) continue;
            for (int j = 1;j < i;j++) {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
            }
        }
        return dp;
    }
};

int main() {
    int numRows = 5;
    auto res = Solution().generate(numRows);
    for (auto &x:res) {
        for (auto &y:x) {
            cout << y << " ";
        }
        cout << '\n';
    }

    return 0;
}