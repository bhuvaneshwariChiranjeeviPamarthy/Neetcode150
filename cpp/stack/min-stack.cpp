#include <cstdio>
#include <cctype>
#include <iostream>
#include <sstream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

class MinStack {
private:
    stack<int> st, minStack;

public:
    MinStack() {
        // No special setup is needed when the stack starts empty.
    }

    void push(int val) {
        st.push(val);

        // We only store values that could be the current minimum.
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }

    void pop() {
        // If the value leaving the main stack is also the current minimum,
        // we remove it from the min stack too.
        if (minStack.top() == st.top()) {
            minStack.pop();
        }
        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minStack.top();
    }
};

vector<string> parseOperations(const string& line) {
    vector<string> operations;
    string current;
    bool insideString = false;

    for (char ch : line) {
        if (ch == '"') {
            if (insideString) {
                operations.push_back(current);
                current.clear();
            }
            insideString = !insideString;
        } else if (insideString) {
            current += ch;
        }
    }

    return operations;
}

vector<vector<int>> parseArguments(const string& line) {
    vector<vector<int>> arguments;
    int i = 0;
    int n = static_cast<int>(line.size());

    while (i < n) {
        if (line[i] == '[') {
            ++i;
            vector<int> current;
            string number;

            while (i < n && line[i] != ']') {
                if (line[i] == '-' || isdigit(line[i])) {
                    number += line[i];
                } else if (!number.empty()) {
                    current.push_back(stoi(number));
                    number.clear();
                }
                ++i;
            }

            if (!number.empty()) {
                current.push_back(stoi(number));
            }

            arguments.push_back(current);
        }
        ++i;
    }

    return arguments;
}

#ifndef ONLINE_JUDGE
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string operationsLine, argumentsLine;
    getline(cin, operationsLine);
    getline(cin, argumentsLine);

    vector<string> operations = parseOperations(operationsLine);
    vector<vector<int>> arguments = parseArguments(argumentsLine);

    MinStack* obj = nullptr;
    vector<string> results;

    for (int i = 0; i < static_cast<int>(operations.size()); ++i) {
        const string& operation = operations[i];

        if (operation == "MinStack") {
            obj = new MinStack();
            results.push_back("null");
        } else if (operation == "push") {
            obj->push(arguments[i][0]);
            results.push_back("null");
        } else if (operation == "pop") {
            obj->pop();
            results.push_back("null");
        } else if (operation == "top") {
            results.push_back(to_string(obj->top()));
        } else if (operation == "getMin") {
            results.push_back(to_string(obj->getMin()));
        }
    }

    cout << "[";
    for (int i = 0; i < static_cast<int>(results.size()); ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << results[i];
    }
    cout << "]\n";

    delete obj;
    return 0;
}
#endif
