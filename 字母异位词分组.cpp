//#include <iostream>
//#include <vector>
//#include <unordered_map>
//#include <algorithm>
//using namespace std;
//class Solution {
//public:
//    vector<vector<string>> groupAnagrams(vector<string>& strs) {
//        unordered_map<string, vector<string>> map;
//        for (string &s:strs) {
//            string key = s;
//            ranges::sort(key);
//            map[key].push_back(s);
//        }
//        vector<vector<string>> res = {};
//        for (auto& x : map) {
//            res.push_back(x.second);
//        }
//        return res;
//    }
//    
//};
//
//
//int main() {
//
//	vector<string> strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
//	Solution solution;
//	vector<vector<string>> result = solution.groupAnagrams(strs);
//	for (const auto& group : result) {
//		cout << "[";
//		for (const auto& word : group) {
//			cout << word << " ";
//		}
//		cout << "]" << endl;
//	}
//
//
//    return 0;
//}
//
