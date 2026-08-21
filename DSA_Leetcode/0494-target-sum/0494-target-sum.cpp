class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int, int> counter;
        counter[0] = 1;

        for (int n : nums) {
            unordered_map<int, int> temp;

            for (const auto& [total, count] : counter) {
                temp[total + n] += count;
                temp[total - n] += count;
            }
            counter = temp;
        }

        return counter[target];        
    }
};