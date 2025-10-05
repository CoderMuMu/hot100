#include <iostream>
#include <functional>
#include <vector>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (auto &p:prerequisites) {
            graph[p[1]].emplace_back(p[0]);
        }
        // 0:"未访问",1:"正在访问",2:"已访问"
        vector<int> state(numCourses,0);
        function<bool(int)> dfs = [&](int i)->bool { // dfs返回的结果表示是否有环
            if (state[i] == 1) return true; // 在当前的dfs路径上，如果再次遇到就是有环
            if (state[i] == 2) return false;
            state[i] = 1;
            for (int &g:graph[i]) {
                if (dfs(g)) {
                    return true;
                }
            }
            state[i] = 2;
            return false;
        };
        for (int i = 0;i < numCourses;i++) {
            if (state[i] == 0 && dfs(i)) { // 没有被访问过，且有环
                return false;
            }
        }
        return true;
    }
};

int main() {
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1,0}};
    Solution sl;
    cout << sl.canFinish(numCourses,prerequisites) << endl;

    return 0;;
}