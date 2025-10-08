#include <functional>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.')); // 初始棋盘
        vector<bool> col(n),diag1(n * 2 - 1),diag2(n * 2 -  1);
        // row 行，col 列
        function<void(int)> dfs = [&](int r)->void {
            if (r == n) {
                ans.emplace_back(board);
                return;
            }
            for(int c = 0;c < n;c++) {
                int rc = r - c + n - 1;
                if (!col[c] && !diag1[r + c] && !diag2[rc]) {
                    board[r][c] = 'Q';
                    col[c] = diag1[r + c] = diag2[rc] = true;
                    dfs(r + 1);
                    col[c] = diag1[r + c] = diag2[rc] = false;
                    board[r][c] = '.';
                }
            }
        };
        dfs(0);
        return ans;
    }
};

int main() {

    int n = 4;
    Solution sl;
    auto ans = sl.solveNQueens(n);
    for (auto &s:ans) {
        for (auto &c:s) {
            cout << c << endl;
        }
        cout << endl;
    }


    return 0;
}

