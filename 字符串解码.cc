#include <cctype>
#include <cstddef>
#include <functional>
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        
        int i = 0;
        function<string()> decode = [&]()->string{
            string res;
            int k = 0;
            while (i < s.size()) {
                char c = s[i];
                i++;
                if (isalpha(c)){
                    res += c;
                }else if (isdigit(c)) {
                    k = k * 10 + c - '0';
                }else{
                    if (c == '[') {
                        string t = decode();
                        for (;k > 0 ;k--) {
                            res += t;
                        }
                    }else{
                        break;
                    }
                }
            }
            return res;
        };
        return decode();
    }
};

int main() {

    string s = "3[a]2[bc]";
    Solution st;
    cout << st.decodeString(s) << endl;


    return 0;
}