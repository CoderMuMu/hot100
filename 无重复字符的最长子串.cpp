//#include <iostream>
//#include <string>
//#include <unordered_map>
//using namespace std;
//
//class Solution {
//public:
//    int lengthOfLongestSubstring(string s) {
//        int ans = 0, n = s.size();
//        unordered_map<char, int> map;
//        int left = 0;
//        for (int right = 0; right < n; right++) {
//            char c = s[right];
//            map[c]++;
//            while (map[c] > 1) {
//                map[s[left]]--;
//                left++;
//            }
//            ans = max(ans, right - left + 1);
//        }
//		return ans;
//    }
//};
//
//int main() {
//    Solution solution;
//    string s = "abcabcbb";
//    cout << solution.lengthOfLongestSubstring(s) << endl; // Output: 3
//    return 0;
//}
