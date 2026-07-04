#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // Step 1: Count the frequency of each number
        unordered_map<int, int> freq;

        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }

        // Step 2: Create a max heap
        // pair<frequency, number>
        priority_queue<pair<int, int>> pq;

        // Step 3: Put every (frequency, number) into the heap
        for (unordered_map<int, int>::iterator it = freq.begin();
             it != freq.end();
             it++) {

            pq.push(make_pair(it->second, it->first));
        }

        // Step 4: Take the top k elements
        vector<int> ans;

        while (k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};