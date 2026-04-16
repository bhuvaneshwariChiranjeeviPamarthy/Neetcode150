#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // Max-heap lets us always pull the two heaviest stones in O(log n).
        priority_queue<int> pq;
        for (auto i : stones) {
            pq.push(i);
        }

        // Repeatedly smash the two heaviest stones.
        while (pq.size() > 1) {
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();

            // If weights differ, the difference goes back into the heap.
            if (second < first) {
                pq.push(first - second);
            }
        }

        // One stone left => return it, otherwise all stones destroyed.
        return pq.size() == 1 ? pq.top() : 0;
    }
};
