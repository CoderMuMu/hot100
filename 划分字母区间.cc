#include <functional>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> ans;
        int cnt[26]{};
        for (char &c:s) {
            cnt[c - 'a']++;
        }
        unordered_map<int,int> mp;
        function<bool()> isCheck = [&]()->bool{
            for (auto &[x,y]:mp) {
                if (cnt[x - 'a'] != 0) return false;
            }
            return true;
        };
        
        int right = -1;
        for (int i = 0;i < n;i++) {
            char c = s[i];
            mp[c];
            cnt[c - 'a']--;
            if (isCheck()) {
                ans.emplace_back(i - right);
                right += i - right;
            }
        }
        return ans;
    }
};

int main() {
    string s = "ababcbacadefegdehijhklij";
    auto res = Solution().partitionLabels(s);
    for (auto &c:res){
        cout << c << " ";
    }

    return 0;
}
