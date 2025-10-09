#include <functional>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(),n = matrix[0].size();
        function<bool(int,int)> find = [&](int row,int col)->bool{
            while (row < m && col >= 0) {
                int x = matrix[row][col];
                if (x < target) {
                    row++;
                }else if (x > target){
                    col--;
                }else{
                    return true;
                }
            }
            return false;
        };
        return find(0,n - 1);
    }
};

int main() {
    Solution sl;
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 3;
    cout << sl.searchMatrix(matrix,target) << endl;
    return 0;
}