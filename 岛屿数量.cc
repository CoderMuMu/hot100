#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

class Solution {
private:
    const int dx[4] {0,0,-1,1};
    const int dy[4] {-1,1,0,0};
public:
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(),n = grid[0].size(),ans = 0;;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        function<void(int,int)> bfs = [&](int x,int y)->void{
            queue<pair<int,int>> q;
            q.push({x,y});
            visited[x][y] = true;
            while (!q.empty()) {
                int i = q.front().first,j = q.front().second;
                q.pop();
                for (int k = 0;k < 4;k++) {
                    int bx = i + dx[k],by = j + dy[k];
                    if (bx >= 0 && bx < m && by >=0 && by < n && grid[bx][by] != '0' && !visited[bx][by]) {
                        visited[bx][by] = true;
                        q.push({bx,by});
                    }
                }
            }
        };
        for (int i = 0;i < m;i++) {
            for (int j = 0;j < n;j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    bfs(i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<char>> grid = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
    Solution sl;
    cout << sl.numIslands(grid) << endl;
    return 0;
}
