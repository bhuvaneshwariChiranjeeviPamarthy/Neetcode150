#include <queue>
#include <vector>
using namespace std;

class KthLargest {
private:
    int k;
    // Min-heap stores only the k largest values seen so far.
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        // Build heap with only k largest elements
        for (auto i : nums) {
            minHeap.push(i);
            // If size exceeds k, remove smallest
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
    }

    int add(int val) {
        // Add new value to heap
        minHeap.push(val);
        // Maintain only k elements in heap
        while (minHeap.size() > k) {
            minHeap.pop();
        }
        // Top of min-heap = kth largest element
        return minHeap.top();
    }
};


// Idea:
// Maintain a min-heap of size k.
// Heap stores k largest elements seen so far.
//
// Why min-heap?
// Smallest among these k elements = kth largest overall.
//
// Steps:
// 1. Push element into heap.
// 2. If heap size > k -> pop smallest.
// 3. Heap always contains top k largest elements.
// 4. Return heap.top().
//
// Time Complexity:
// add() -> O(log k)
//
// Space:
// O(k)

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
