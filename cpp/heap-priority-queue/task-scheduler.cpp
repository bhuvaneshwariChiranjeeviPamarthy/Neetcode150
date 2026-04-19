#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //Hashmap to store the frequencies.
        unordered_map<char, int> freq;
        for(char &ch : tasks){
            freq[ch]++;
        }

        //maxHeap will pick the highest freq task.
        priority_queue<int> maxHeap;
        for(auto &[task, count]: freq){
            maxHeap.push(count);
        }

        queue<pair<int, int>> q;  // {remainingCount, availableTime}
        int time = 0;

        //At each time unit -> release cooled tasks -> run ONE best task -> put it back with cooldown.
        while(!q.empty() || !maxHeap.empty()){
            time++;

            // Step 1: release tasks from cooldown
            //if queueFront has a task which has finished the coolDown. then push it to the maxHeap.
            if(!q.empty() && q.front().second == time){
                maxHeap.push(q.front().first);
                //Remove it from the queue.
                q.pop();
            }

            // Step 2: execute one task
            //If any task available do it.
            if(!maxHeap.empty()){
                int cnt = maxHeap.top();
                maxHeap.pop();
                cnt--;

                //If task is not done, put it in the coolDown queue.
                if(cnt > 0){
                    //For Ex: t = 0, n = 1 then cool down = 0 + 1 = 1 {A, A, B} , N = 2. A B_ A
                    //IF WE USE A AT 0 WE CAN USE IT ONLY AT 1. - SO WE STORE {1,1}.
                    q.push({cnt, time + n + 1});
                }

            }
        }
        return time;
    }
};
