#include <functional>
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (char &c:s) {
            if (c == '(') {
                stk.push(')');
            }else if (c == '{'){
                stk.push('}');
            }else if (c == '['){
                stk.push((']'));
            }else{
                if (stk.empty() || stk.top() != c) {
                    return false;
                }
                stk.pop();
            }
        }
        
        return stk.size() == 0;
    }
};

int main() {
    string s = "()";
    Solution st;
    cout << st.isValid(s) << endl;

    return 0;
}