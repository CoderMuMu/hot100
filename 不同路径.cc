#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<long long>> dp(m + 1,(vector<long long>(n + 1)));
        for (int i = 0;i < m;i++) dp[i][0] = 1;
        for (int j = 0;j < n;j++) dp[0][j] = 1;
        for (int i = 1;i < m;i++) {
            for (int j = 1;j < n;j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main() {

    int m = 7,n = 3;
    cout << Solution().uniquePaths(m, n) << endl;

    return 0;
}