#include <functional>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    bool isPlaindRome(const string &s,int left,int right) {
        while (left < right) {
            if (s[left++] != s[right--]) {
                return false;
            }
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> ans;
        vector<string> path;
        // 第i个逗号选或者不选
        // 当前字符串从start位置开始
        function<void(int,int)> dfs = [&](int i,int start)->void{
            if (i == n) {
                ans.emplace_back(path);
                return;
            }
            
            // 不选
            if (i < n - 1) {
                dfs(i + 1,start);
            }

            // 选
            if (isPlaindRome(s,start,i)) {
                string temp = s.substr(start,i - start + 1);
                path.emplace_back(temp);
                // start 从i+1开始
                dfs(i + 1,i + 1);
                path.pop_back();
            }
        };
        dfs(0,0);
        return ans;
    }
};

int main() {
    
    string s = "aab";
    Solution sl;
    auto ans = sl.partition(s);
    for (auto &s:ans) {
        for (auto &c:s) {
            cout << c << " ";
        }
        cout << endl;
    }

    return 0;
}
