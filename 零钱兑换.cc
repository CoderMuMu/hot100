#include <functional>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int mem[13][10001];
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        auto init = [](){
            memset(mem,-1,sizeof(mem));
            return 0;
        }();
        function<int(int,int)> dfs = [&](int i,int j)->int{
            if (i < 0) {
                return j == 0 ? 0 : INT_MAX / 2;
            }
            int &res = mem[i][j];
            if (res != -1) {
                return res;
            }
            if (j < coins[i]) {
                return res = dfs(i - 1,j);
            }else{
                return res = min(dfs(i - 1,j),dfs(i,j - coins[i]) + 1);
            }
        };
        int ans = dfs(n - 1,amount);
        return ans < INT_MAX / 2 ? ans : -1;
    }
};


int main() {

    vector<int> coins = {2};
    int amount = 3;
    cout << Solution().coinChange(coins,amount) << '\n';
    return 0;
}