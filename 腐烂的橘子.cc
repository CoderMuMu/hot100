#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
private:
    const int dx[4] {0,0,-1,1};
    const int dy[4] {-1,1,0,0};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        int fresh = 0;
        queue<pair<int,int>> Rotten; // 坏橘子
        for (int i = 0;i < m;i++) {
            for (int j = 0;j < n;j++) {
                if (grid[i][j] == 1) {
                    fresh++;
                }else if (grid[i][j] == 2) {
                    Rotten.push({i,j});
                }
            }
        }
        int time = 0;
        while (fresh > 0 &&!Rotten.empty()) {
            int size = Rotten.size();
            for (int i = 0;i < size;i++) {
                int x = Rotten.front().first,y = Rotten.front().second;
                Rotten.pop();
                for (int k = 0;k < 4;k++) {
                    int bx = x + dx[k],by = y + dy[k];
                    if (bx >= 0 && bx < m && by >= 0 && by < n && grid[bx][by] == 1) {
                        grid[bx][by] = 2;
                        Rotten.push({bx,by});
                        fresh--;
                    }
                }
            }
            time++;
        }
        return fresh > 0 ? -1 : time;
    }
};

int main() {
    vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    Solution sl;
    cout << sl.orangesRotting(grid) << endl;

    return 0;
}