#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0);

        for (int i = 0; i < n; i++) {
            int count = 0;

            // Look ahead until we find a warmer day for the current temperature.
            for (int j = i + 1; j < n; j++) {
                count++;
                if (temperatures[j] > temperatures[i]) {
                    answer[i] = count;
                    break;
                }
            }
        }

        return answer;
    }
};

vector<int> parseArray(const string& line) {
    vector<int> values;
    string number;

    for (char ch : line) {
        if (ch == '-' || (ch >= '0' && ch <= '9')) {
            number += ch;
        } else if (!number.empty()) {
            values.push_back(stoi(number));
            number.clear();
        }
    }

    if (!number.empty()) {
        values.push_back(stoi(number));
    }

    return values;
}

void printArray(const vector<int>& values) {
    cout << "[";
    for (int i = 0; i < static_cast<int>(values.size()); i++) {
        if (i > 0) {
            cout << ",";
        }
        cout << values[i];
    }
    cout << "]\n";
}

#ifndef ONLINE_JUDGE
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string line;
    getline(cin, line);

    vector<int> temperatures = parseArray(line);
    Solution sol;
    vector<int> answer = sol.dailyTemperatures(temperatures);
    printArray(answer);

    return 0;
}
#endif
