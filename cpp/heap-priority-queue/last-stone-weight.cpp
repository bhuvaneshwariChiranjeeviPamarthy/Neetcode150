#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto i: stones){
            pq.push(i);
        }
        //SMASH STONES
        while(pq.size() > 1){
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            if(second < first){
                pq.push(first - second);
            }
        }
        return pq.size() == 1? pq.top() : 0;
    }
};
