class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for (int i = 0; i < nums.size(); i++) {
            if (freq.find(nums[i]) != freq.end()) {
                freq[nums[i]]++;
            } else {
                freq[nums[i]] = 1;
            }
        }

        vector<pair<int, int>> elements;
        for (unordered_map<int, int>::iterator it = freq.begin(); it != freq.end(); it++) {
            elements.push_back(make_pair(it->first, it->second));
        }

        sort(elements.begin(), elements.end(), [](pair<int, int> a, pair<int, int> b) {
            if (a.second > b.second) {
                return true;
            } else {
                return false;
            }
        });

        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(elements[i].first);
        }

        return result;
    }
};
