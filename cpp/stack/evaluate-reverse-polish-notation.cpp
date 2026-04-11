#include <cstdio>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int a, b;
        stack<int> st;

        for (const string& token : tokens) {
            // When we see an operator, we use the two most recent numbers.
            if (token == "+") {
                b = st.top();
                st.pop();
                a = st.top();
                st.pop();
                st.push(a + b);
            } else if (token == "/") {
                b = st.top();
                st.pop();
                a = st.top();
                st.pop();
                st.push(a / b);
            } else if (token == "*") {
                b = st.top();
                st.pop();
                a = st.top();
                st.pop();
                st.push(a * b);
            } else if (token == "-") {
                b = st.top();
                st.pop();
                a = st.top();
                st.pop();
                st.push(a - b);
            } else {
                // Regular numbers just go onto the stack until an operator needs them.
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};

vector<string> parseTokens(const string& line) {
    vector<string> tokens;
    string current;
    bool insideString = false;

    for (char ch : line) {
        if (ch == '"') {
            if (insideString) {
                tokens.push_back(current);
                current.clear();
            }
            insideString = !insideString;
        } else if (insideString) {
            current += ch;
        }
    }

    return tokens;
}

#ifndef ONLINE_JUDGE
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string tokensLine;
    getline(cin, tokensLine);

    vector<string> tokens = parseTokens(tokensLine);
    Solution sol;
    cout << sol.evalRPN(tokens) << "\n";

    return 0;
}
#endif
