#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int result = 0;
        int n = static_cast<int>(heights.size());

        // Try every bar as the limiting height.
        for (int i = 0; i < n; i++) {
            int left = i, right = i;

            // Extend to the left while bars are at least as tall as heights[i].
            while (left - 1 >= 0 && heights[left - 1] >= heights[i]) {
                left--;
            }

            // Extend to the right while bars are at least as tall as heights[i].
            while (right + 1 < n && heights[right + 1] >= heights[i]) {
                right++;
            }

            int width = right - left + 1;
            result = max(result, heights[i] * width);
        }

        return result;
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

#ifndef ONLINE_JUDGE
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string line;
    getline(cin, line);
    vector<int> heights = parseArray(line);

    Solution sol;
    cout << sol.largestRectangleArea(heights) << "\n";

    return 0;
}
#endif
