class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> map;
        int longestStreak = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (map.find(nums[i]) == map.end()) {
                int left, right;

                if (map.find(nums[i] - 1) != map.end()) {
                    left = map[nums[i] - 1];
                } else {
                    left = 0;
                }

                if (map.find(nums[i] + 1) != map.end()) {
                    right = map[nums[i] + 1];
                } else {
                    right = 0;
                }

                int sequenceLength = left + 1 + right;

                map[nums[i]] = sequenceLength;
                map[nums[i] - left] = sequenceLength;
                map[nums[i] + right] = sequenceLength;

                if (sequenceLength > longestStreak) {
                    longestStreak = sequenceLength;
                }
            }
        }

        return longestStreak;
    }
};
