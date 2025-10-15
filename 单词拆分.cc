#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(),wordDict.end());
        int n = s.size();
        vector<bool> dp(n + 1,false);
        dp[0] = true;
        for (int i = 1;i <= n;i++) {
            for (int j = 0;j < i;j++) {
                if (dp[j] && st.count(s.substr(j,i - j))){
                    dp[i] = true;
                    break; // 说明当前以i为结尾的字符串可以由字典构成，dp[i]有效
                }
            }
        }
        return dp[n];
    }
};

int main() {
    string s = "leetcode";
    vector<string> wordDict = {"leet","code"};
    cout << Solution().wordBreak(s,wordDict) << endl;
    return 0;
}