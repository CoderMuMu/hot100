#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
        int m = s.size(),n = t.size();
        vector<vector<int>> dp(m + 1,vector<int>(n + 1,0));
        // dp[0][0] = (s[0] == t[0] ? 1 : 0); 不对，两个空字符串的最长公共子序列应该是0
        for (int i = 1;i <= m;i++) {
            for (int j = 1;j <= n;j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }else{
                    dp[i][j] = max(dp[i][j - 1],dp[i - 1][j]);
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
    string s = "abcde",t = "ace";
    cout << Solution().longestCommonSubsequence(s, t) << '\n';
    return 0;
}