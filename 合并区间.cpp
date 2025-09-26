//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//class Solution {
//public:
//    vector<vector<int>> merge(vector<vector<int>>& intervals) {
//        ranges::sort(intervals);
//        vector<vector<int>> merged;
//		int n = intervals.size();
//        merged.push_back(intervals[0]);
//        for (int i = 1; i < n;i++) {
//			auto p = intervals[i];
//            if ( merged.back()[1] >= p[0]) {
//                merged.back()[1] = max(merged.back()[1], p[1]);
//            }
//            else {
//				merged.push_back(p);
//            }
//        }
//		return merged;
//    }
//};
//
//int main() {
//    Solution solution;
//    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
//    vector<vector<int>> result = solution.merge(intervals);
//    cout << "Merged intervals: ";
//    for (const auto& interval : result) {
//        cout << "[" << interval[0] << "," << interval[1] << "] ";
//    }
//    cout << endl; // Output: [[1,6],[8,10],[15,18]]
//    return 0;
//}