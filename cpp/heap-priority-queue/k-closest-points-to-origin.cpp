#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> result;
        // minHeap will store: {distanceSquared, {x, y}}
        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > minHeap;

        // Push all points with their squared distance
        for(auto &point: points){
            int x = point[0];
            int y = point[1];
            int dist = x*x + y*y;
            minHeap.push({dist, {x, y}});
        }
        // Extract k closest points
        while(k--){
            auto topElement = minHeap.top();
            minHeap.pop();

            int firstEle = topElement.second.first;
            int secondEle = topElement.second.second;

            result.push_back({firstEle, secondEle});
        }
        return result;
    }
};
