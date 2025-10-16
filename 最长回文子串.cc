#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        // 预处理，让字符串都变成奇数长度，逻辑统一，^#a#b#c#$
        string t = "^";
        for (char &c:s) {
            t += '#';
            t += c;
        }
        t += "#$";
        vector<int> halfLen(t.size() - 2);
        halfLen[1] = 1;
        int mid = 0,right = 0, ans_mid = 0;
        for (int i = 2;i < t.size() - 2;i++) {
            int hl = 1;
            // 算法关键，利用对称性
            if (i < right) {
                int i1 = 2 * mid - i;// i1是i的对称点。
                // 我把i的左边界到i，以及i到right，分别称作左半段和右半段
                // 如果左半段长，则right - i小并且有效，左半段i1是无效的。取right - i
                // 否则，右半段长，right - i的对称点是非法的，那么i1是有效的，取halfLen[i1]
                // 总结，这一步的作用是i在已知的最长回文子串中，尽可能地获取有效地以i为中心的半径
                hl = min(halfLen[i1],right - i);
            }
            // 中心扩展
            while (t[i - hl] == t[i + hl]) {
                hl++;
                mid = i;
                right = i + hl;
            }
            // 更新全局最优
            halfLen[i] = hl;
            if (hl > halfLen[ans_mid]) {
                ans_mid = i;
            }
        }
        int hl = halfLen[ans_mid];
        // h1 - 1的原因:假设源字符串长度为x，预处理后添加了x + 1 个 '#'
        // 预处理后的字符串长度为 2 * x + 1 = 2 * h1 - 1 => x = h1 - 1
        return s.substr((ans_mid - hl) / 2, hl - 1);
    }
};

int main() {

    string s = "babad";
    cout << Solution().longestPalindrome(s) << endl;
    return 0;
}
