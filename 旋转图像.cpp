//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Solution {
//public:
//    void rotate(vector<vector<int>>& matrix) {
//        int n = matrix.size();
//        //先转置
//        for (int i = 0; i < n; i++) {
//            for (int j = 0; j < i; j++) {
//                swap(matrix[i][j],matrix[j][i]);
//            }
//        }
//        //在逐行翻转
//        for (auto& p : matrix) {
//			reverse(p.begin(), p.end());
//        }
//    }
//};
//
//int main() {
//    Solution solution;
//    vector<vector<int>> matrix = {
//        {1,2,3},
//        {4,5,6},
//        {7,8,9}
//    };
//    solution.rotate(matrix);
//    cout << "Rotated matrix: " << endl;
//    for (const auto& row : matrix) {
//        for (int num : row) {
//            cout << num << " ";
//        }
//        cout << endl;
//    }
//    // Output:
//    // 7 4 1
//    // 8 5 2
//    // 9 6 3
//    return 0;
//}
//
