#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.emplace_back(-1);
        stack<int> st;
        st.push(-1);
        int ans = 0;
        for (int right = 0;right < heights.size();right++) {
            int h = heights[right];
            while (st.size() > 1 && heights[st.top()] >= h){
                int i = st.top();
                st.pop();
                int left = st.top();
                ans = max(ans,heights[i] * (right - left - 1));
            }
            st.push(right);
        }

        return ans;
    }
};

int main() {
    vector<int> heights = {2,1,5,6,2,3};
    Solution st;
    cout << st.largestRectangleArea(heights) << endl;


    return 0;
}