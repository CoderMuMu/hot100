//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//class Solution {
//public:
//    bool isEqual(const vector<int> &a,const vector<int> &b) {
//        for (int i = 0; i < 26; i++) {
//            if (a[i] != b[i]) return false;
//        }
//        return true;
//    }
//    vector<int> findAnagrams(string s, string p) {
//        vector<int> cnt_s(26,0), cnt_p(26,0);
//        for (char& c : p) {
//            cnt_p[c - 'a']++;
//        }
//		vector<int> ans;
//        int len_p = p.size();
//        int left = 0;
//        for (int right = 0; right < s.size();right++) {
//            char c = s[right];
//            cnt_s[c - 'a']++;
//            if (right - left + 1 != len_p) {
//                continue;
//            }
//            if (isEqual(cnt_s, cnt_p)) {
//                ans.push_back(left);
//            }
//            cnt_s[s[left++] - 'a']--;
//        }
//        return ans;
//    }
//};
//
//int main() {
//    Solution solution;
//    string s = "cbaebabacd", p = "abc";
//    vector<int> ans = solution.findAnagrams(s, p);
//    for (int index : ans) {
//        cout << index << " ";
//    }
//    cout << endl; // Output: [0, 6]
//    return 0;
//}
