#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <functional>
using namespace std;

class Solution {
private:
    map<int,string> number = {{0,""},{1,""},{2,"abc"},{3,"def"},{4,"ghi"}
                    ,{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}};
public:
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        vector<string> ans;
        string path(n,' ');
        function<void(int)> dfs = [&](int i)->void{
            if (i == n) {
                ans.emplace_back(path);
                return;
            }
            for (char &c:number[digits[i] - '0']) {
                path[i] = c;
                dfs(i + 1);
            }
        };
        dfs(0);
        return ans;
    }
};

int main() {

    string digits = "23";
    Solution sl;
    vector<string> ans = sl.letterCombinations(digits);
    for (string &s:ans) {
        cout << s << " ";
    }

    return 0;
}
