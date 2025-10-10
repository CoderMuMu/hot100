#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        if (a.size() > b.size()) {
            swap(a,b);
        }
        // int i = left + (right - left) / 2;
        // int j = (m + n + 1) / 2 - (i + 1) - 1;
        // max(ai,bj) <= min(ai+1,bj+1) => ai <= bj+1 && bj <= ai+1
        int m = a.size(),n = b.size();
        int left = -1,right = m;
        while (left + 1 < right) {
            int i = left + (right - left) / 2;
            int j = (m + n + 1) / 2 - (i + 1) - 1;
            if (a[i] <= b[j + 1]){
                left = i;
            }else{
                right = i;
            }
        }
        // ai <= bj+1 &&  ai+1 >= bj+1>= bj
        // 循环结束后left是满足a[i] <= b[j+1]的最后一个位置

        int i = left; 
        int j = (m + n + 1) / 2 - (i + 1) -1;
        int ai = i >= 0 ? a[i] : INT_MIN;
        int ai1 = i + 1 < m ? a[i + 1] : INT_MAX; 
        int bj = j >= 0 ? b[j] : INT_MIN; 
        int bj1 = j + 1 < n ? b[j + 1] : INT_MAX;
        int max1 = max(ai,bj),min2 = min(ai1,bj1);
        return (m + n) % 2 == 1 ? max1 : (max1 + min2) / 2.0; 
    }
};

int main() {
    vector<int> nums1 = {1,5,6,9,10};
    vector<int> nums2 = {2,3,4,7,8};
    Solution st;
    cout << st.findMedianSortedArrays(nums1, nums2) << endl;
}
