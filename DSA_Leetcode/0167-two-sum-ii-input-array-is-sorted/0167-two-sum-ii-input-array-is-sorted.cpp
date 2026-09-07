class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int n = nums.size();
        int l = 0, r = n-1;

        while (l < r) {
            int sum = nums[l] + nums[r];

            if (sum == target) return { l+1, r+1 };
            if (sum < target) l++;
            if (sum > target) r--;
        }

        return {};  //No Soln Found ( Not Possible for this Question )
    }
};