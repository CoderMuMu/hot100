#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minDistance(string s, string t) {
        int m = s.size(),n = t.size();
        vector<vector<int>> dp(m + 1,vector<int>(n + 1,0));
        // 不要忘记初始化，后续状态转移需要依赖这些初始值
        for (int i = 0;i <= m;i++) dp[i][0] = i;
        for (int j = 0;j <= n;j++) dp[0][j] = j;
        for (int i = 1;i <= m;i++) {
            for (int j = 1;j <= n;j++) {
                if (s[i - 1] == t[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1];
                }else {
                    dp[i][j] = min(dp[i-1][j-1],min(dp[i][j - 1],dp[i - 1][j])) + 1;
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
    string s = "horse",t = "ros";
    cout << Solution().minDistance(s, t) << endl;

    return 0;
}
