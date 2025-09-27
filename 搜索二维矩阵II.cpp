//#include <iostream>
//using namespace std;
//#include <vector>
//
//class Solution {
//public:
//    bool searchMatrix(vector<vector<int>>& matrix, int target) {
//        int m = matrix.size(), n = matrix[0].size();
//        int i = 0, j = n - 1;
//        while (i < m && j >= 0) {
//            if (matrix[i][j] == target) return true;
//            else if (matrix[i][j] > target) j--;
//			else i++;
//        }
//        return false;
//    }
//};
//
//int main() {
//    Solution solution;
//    vector<vector<int>> matrix = {
//        {1, 3, 5, 7},
//        {10, 11, 16, 20},
//        {23, 30, 34, 60}
//    };
//    int target = 3;
//    bool result = solution.searchMatrix(matrix, target);
//    cout << "Target " << target << (result ? " found" : " not found") << " in the matrix." << endl; // Output: true
//    return 0;
//}