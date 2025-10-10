#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        vector<int> ans(n,0);
        stack<int> stk;
        for (int i = 0;i < n;i++) {
            while (!stk.empty() && t[stk.top()] < t[i]) {
                ans[stk.top()] = i - stk.top();
                stk.pop();
            }
            stk.push(i);
        }

        return ans;
    }
};

int main(){
    vector<int> temperatures = {73,74,75,71,69,72,76,73};
    Solution st;
    vector<int> ans = st.dailyTemperatures(temperatures);
    for (int &x:ans) {
        cout << x << " ";
    }

    return 0;
}