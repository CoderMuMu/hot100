//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//class Solution {
//public:
//    bool isCoverAll(const vector<int>& a, const vector<int>& b) {
//        for (char i = 'a'; i <= 'z'; i++) {
//            if (a[i] < b[i]) return false;
//        }
//        for (char i = 'A'; i <= 'Z'; i++) {
//            if (a[i] < b[i]) return false;
//        }
//        return true;
//    }
//    string minWindow(string s, string t) {
//        if (s.size() < t.size()) return "";
//        vector<int> cnt_s(128, 0), cnt_t(128, 0);
//        for (char& c : t) {
//            cnt_t[c]++;
//        }
//        int n = s.size();
//        int left = 0, ans_left = -1, ans_right = s.size();
//        for (int right = 0; right < n; right++) {
//            char c = s[right];
//            cnt_s[c]++;
//            while (isCoverAll(cnt_s, cnt_t)) {
//                if (right - left < ans_right - ans_left) {
//                    ans_right = right;
//                    ans_left = left;
//                }
//                cnt_s[s[left]]--;
//                left++;
//            }
//        }
//        return ans_left < 0 ? "" : s.substr(ans_left, ans_right - ans_left + 1);
//    }
//};
//
//int main() {
//    Solution solution;
//    string s = "ADOBECODEBANC", t = "ABC";
//    cout << solution.minWindow(s, t) << endl; // Output: "BANC"
//    return 0;
//}
