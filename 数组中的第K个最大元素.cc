#include <functional>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        function<int(int,int,int)> quick_sort = [&](int start,int end,int k)->int{
            if (start >= end) {
                return nums[start];
            }
            int random_idx = start + rand() % (end - start + 1);//[0,end - start] [start,end]
            swap(nums[start],nums[random_idx]);
            int index = start,i = start - 1,j = end + 1,temp = nums[start];
            while (index < j) {
                if (nums[index] < temp) {
                    swap(nums[index++],nums[++i]);
                }else if (nums[index] > temp) {
                    swap(nums[index],nums[--j]);
                }
                else index++;
            }
            int left_size = i - start + 1;
            int mid_size = j - i - 1;
            if (k <= left_size){
                return quick_sort(start,i,k);
            }else if (k <= left_size + mid_size) {
                return temp;
            }else{
                return quick_sort(j,end,k - left_size - mid_size);
            }
        };
        return quick_sort(0,n - 1,n - k + 1);
    }
};

void quick_sort(vector<int> &nums,int start,int end){
    if (start >= end) {
        return;
    }
    int random_idx = start + rand() % (end - start + 1);
    swap(nums[start],nums[random_idx]);
    int temp = nums[start],i = start - 1,j = end + 1,index = start;
    while (index < j) {
        if (nums[index] < temp) {
            swap(nums[index++],nums[++i]);
        }else if (nums[index] > temp) {
            swap(nums[index],nums[--j]);
        }else{
            index++;
        }
    }
    if (i >= start) quick_sort(nums,start,i);
    if (j <= end) quick_sort(nums,j,end);
}

int main() {
    vector<int> nums = {3,2,1,5,6,4};
    int n = nums.size();
    quick_sort(nums,0,n - 1);
    for (int &x:nums) {
        cout << x << " ";
    }
    return 0;
}