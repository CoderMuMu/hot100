#include <iostream>
#include <vector>
#include <functional>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string path;
        // dfs(i,left) 表示第i个位置放什么，已经有left个左括号
        function<void(int,int)> dfs = [&](int i,int left)->void {
            if (i == 2 * n) {
                ans.emplace_back(path);
                return;
            }

            // 选左括号
            if (left < n) {
                path.push_back('(');
                dfs(i + 1,left + 1);
                path.pop_back();
            }

            // 选右括号
            if (i - left < left) {
                path.push_back(')');
                dfs(i + 1,left);
                path.pop_back();
            }
        };
        dfs(0,0);
        return ans;
    }
};

int main() {

    int n = 3;
    Solution sl;
    auto ans = sl.generateParenthesis(n);
    for (string &s:ans) {
        cout << s << " ";
    }

    return 0;
}