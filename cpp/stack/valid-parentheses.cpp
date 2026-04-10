#include <cstdio>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<int> st;

        for (auto ch : s) {
            // Opening brackets stay on the stack until we find their match.
            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            } else {
                // If nothing is open, this closing bracket has no partner.
                if (st.empty()) {
                    return false;
                }

                // The latest open bracket has to match the current closing one.
                if (ch == ')' && st.top() != '(') {
                    return false;
                }
                if (ch == ']' && st.top() != '[') {
                    return false;
                }
                if (ch == '}' && st.top() != '{') {
                    return false;
                }

                st.pop();
            }
        }

        // If something is still left open, the string is not balanced.
        return st.empty();
    }
};

#ifndef ONLINE_JUDGE
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Solution sol;
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;
        cout << boolalpha << sol.isValid(s) << "\n";
    }

    return 0;
}
#endif
