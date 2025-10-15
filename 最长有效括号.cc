#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size(),maxLen = 0;
        vector<int> dp(n + 1,0);// dp[i]表示以第i个字符结尾的最长有效括号长度
        for (int i = 1;i < n;i++) {
            if (s[i] == ')') { // 只有右括号才能参与dp的计算    
                if(s[i] == '(') { // 找到了左括号直接有效长度+2
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                }else if (s[i] == ')') {//"))"形式，需要向前继续找左括号，尝试匹配
                    int preLen = dp[i - 1];// 有效长度
                    int leftPos = i - preLen - 1; // ((i - 1) - preLen + 1) - 1
                    if (leftPos >= 0 && s[leftPos] == '(') {// 是左括号
                        dp[i] = dp[i - 1] + 2;
                        if (leftPos > 0) {// 加上左括号前面的长度
                            dp[i] += dp[leftPos - 1];
                        }
                    }
                }
            }
            maxLen = max(maxLen,dp[i]);
        }

        return maxLen;
    }
};

int main() {

    string s = "(()";
    cout << Solution().longestValidParentheses(s) << endl;

    return 0;
}