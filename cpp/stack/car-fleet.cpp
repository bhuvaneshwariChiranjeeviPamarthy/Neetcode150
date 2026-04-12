#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        vector<pair<int, int>> carS;
        for (int i = 0; i < n; i++) {
            carS.push_back({position[i], speed[i]});
        }

        sort(carS.begin(), carS.end());
        int fleets = 0;
        double fleetTime = 0.0;

        // We move from the car closest to the target back to the farthest one.
        for (int i = n - 1; i >= 0; i--) {
            double currTime = static_cast<double>(target - carS[i].first) / carS[i].second;

            // A car starts a new fleet only if it reaches later than the fleet ahead.
            if (currTime > fleetTime) {
                fleets++;
                fleetTime = currTime;
            }
        }

        return fleets;
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

    string targetLine, positionLine, speedLine;
    getline(cin, targetLine);
    getline(cin, positionLine);
    getline(cin, speedLine);

    int target = stoi(targetLine);
    vector<int> position = parseArray(positionLine);
    vector<int> speed = parseArray(speedLine);

    Solution sol;
    cout << sol.carFleet(target, position, speed) << "\n";

    return 0;
}
#endif
