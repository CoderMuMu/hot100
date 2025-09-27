//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Solution {
//public:
//	//右下左上
//	vector<int> dx = { 0,1,0,-1 };//行
//	vector<int> dy = { 1,0,-1,0 };//列
//    vector<int> spiralOrder(vector<vector<int>>& matrix) {
//		int m = matrix.size(), n = matrix[0].size();
//		vector<int> ans;
//		int k = m * n, x = 0, y = 0, d = 0;
//		for (int i = 0; i < k; i++) {
//			ans.push_back(matrix[x][y]);
//			matrix[x][y] = 101;//标记已经访问过
//			int a = x + dx[d], b = y + dy[d];
//			if (a < 0 || a >= m || b < 0 || b >= n || matrix[a][b] == 101) {
//				d = (d + 1) % 4;
//				x += dx[d];
//				y += dy[d];
//			}
//			else {
//				x = a;
//				y = b;
//			}
//			
//		}
//
//		return ans;
//    }
//};
//
//int main() {
//	Solution solution;
//	vector<vector<int>> matrix = {
//		{1,2,3},
//		{4,5,6},
//		{7,8,9}
//	};
//	vector<int> result = solution.spiralOrder(matrix);
//	cout << "Spiral order: ";
//	for (int num : result) {
//		cout << num << " ";
//	}
//	cout << endl; // Output: [1,2,3,6,9,8,7,4,5]
//	return 0;
//}