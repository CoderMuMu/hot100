#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int cache[101][10001];

auto init = [] {
    memset(cache,-1,sizeof(cache));
    return 0;
}();
class Solution {
public:
    int numSquares(int n) {
        
        function<int(int,int)> dfs = [&](int i,int j)->int {
            if (i == 0) {
                return j == 0 ? 0 : INT_MAX;
            }
            int &res = cache[i][j];
            if (res != -1) {
                return res;
            }
            if (j < i * i) {
                return dfs(i - 1,j);
            }
            else res = min(dfs(i - 1,j),dfs(i,j - i * i) + 1);
            return res;
        };
        return dfs((int)sqrt(n),n);
    }
};

int main() {
    int n = 12;
    Solution st;
    cout << st.numSquares(n) << endl;
    return 0;
}