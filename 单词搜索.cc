#include <functional>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
private:
    static constexpr int dx[4]{0,0,-1,1};
    static constexpr int dy[4]{-1,1,0,0};
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(),n = board[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));

        // 优化一：board中的某个字符比word中的多时
        unordered_map<char,int> cnt_board;
        for (auto &b:board) {
            for (char &c:b) {
                cnt_board[c]++;
                
            }
        }
        unordered_map<char,int> cnt_word;
        for (char &w:word) {
            cnt_word[w]++;
            if (cnt_word[w] > cnt_board[w]) return false;
        }
        

        // 优化二：将word按照首尾字符权重翻转，权重小的在前，先遍历出现次数少的
        if (cnt_word[word.back()] < cnt_word[0]) {
            reverse(word.begin(),word.end());
        }


        function<bool(int,int,int)> dfs = [&](int i,int j,int k)->bool{
            if (board[i][j] != word[k]) {
                return false;
            }
            if (k + 1 == word.size()) {
                return true;
            }
            visited[i][j] = true;
            for (int d = 0;d < 4;d++) { // 这里不用k，防止变量名冲突
                int bx = i + dx[d],by = j + dy[d];
                if (0 <= bx && bx < m && 0 <= by && by < n && !visited[bx][by]) {
                    if (dfs(bx,by,k + 1)) { // 遍历的是{bx,by}，即下一个位置
                        return true;
                    }
                }
            }
            visited[i][j] = false;
            return false;
        };  
        for (int i = 0;i < m;i++) {
            for (int j = 0;j < n;j++) {
                if (dfs(i,j,0)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCCED";
    Solution sl;
    cout << sl.exist(board,word);


    return 0;
}
