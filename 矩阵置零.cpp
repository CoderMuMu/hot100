//#include <iostream>
//#include <vector>
//using namespace std;
//
////class Solution {
////public:
////    void setZeroes(vector<vector<int>>& matrix) {
////		int m = matrix.size(), n = matrix[0].size();
////		vector<int> row(m, 0), col(n, 0);
////		for (int i = 0; i < m; i++) {
////			for (int j = 0; j < n; j++) {
////				if (matrix[i][j] == 0) {
////					row[i] = 1;
////					col[j] = 1;
////				}
////			}
////		}
////		for (int i = 0; i < m; i++) {
////			for (int j = 0; j < n; j++) {
////				if (row[i] == 1 || col[j] == 1) {
////					matrix[i][j] = 0;
////				}
////			}
////		}
////    }
////};
//class Solution {
//public:
//	void setZeroes(vector<vector<int>>& matrix) {
//		int m = matrix.size(), n = matrix[0].size();
//		if (m == 0) return;
//		bool firstRowZero = false, firstColZero = false;
//		//��ǵ�һ�к͵�һ���Ƿ���0
//		for (int j = 0; j < n; j++) {
//			if (!matrix[0][j]) {
//				firstRowZero = true;
//				break;
//			}
//		}
//
//		for (int i = 0; i < m; i++) {
//			if (!matrix[i][0]) {
//				firstColZero = true;
//				break;
//			}
//		}
//
//		//ʹ�õ�һ�к͵�һ�б�Ǽ�¼���������Ƿ���0
//		for (int i = 1; i < m; i++) {
//			for (int j = 1; j < n; j++) {
//				if (!matrix[i][j]) {
//					matrix[i][0] = 0;
//					matrix[0][j] = 0;
//				}
//			}
//		}
//		//�õ�һ�к͵�һ�б�Ǹ�����������
//		for (int i = 1; i < m; i++) {
//			for (int j = 1; j < n; j++) {
//				if (!matrix[i][0] || !matrix[0][j]) {
//					matrix[i][j] = 0;
//				}
//			}
//		}
//		//���µ�һ�к͵�һ��
//		for (int j = 0; j < n; j++) {
//			if (firstRowZero) {
//				matrix[0][j] = 0;
//			}
//		}
//		for (int i = 0; i < m; i++) {
//			if (firstColZero) {
//				matrix[i][0] = 0;
//			}
//		}
//	}
//};
//
//
//int main() {
//	Solution solution;
//	vector<vector<int>> matrix = {
//		{1, 1, 1},
//		{1, 0, 1},
//		{1, 1, 1}
//	};
//	solution.setZeroes(matrix);
//	cout << "Matrix after setting zeroes:" << endl;
//	for (const auto& row : matrix) {
//		for (int val : row) {
//			cout << val << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}