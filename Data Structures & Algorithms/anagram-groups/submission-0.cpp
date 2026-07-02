class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> wrd;

        // build the groups
        for (int i = 0; i < strs.size(); i++) {
            string copy = strs[i];
            sort(copy.begin(), copy.end());

            wrd[copy].push_back(strs[i]);
        }

        vector<vector<string>> result;

        // move values from map to result
        for (unordered_map<string, vector<string>>::iterator it = wrd.begin(); it != wrd.end(); it++) {
            result.push_back(it->second);
        }

        return result;
    }
};