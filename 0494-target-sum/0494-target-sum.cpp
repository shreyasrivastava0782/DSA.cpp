class Solution {
public:
    int f(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> prev(target + 1, 0), curr(target + 1, 0);

        if (nums[0] == 0) prev[0] = 2;
        else prev[0] = 1;

        if (nums[0] != 0 && nums[0] <= target)
            prev[nums[0]] = 1;

        for (int i = 1; i < n; i++) {
            fill(curr.begin(), curr.end(), 0);   

            for (int sum = 0; sum <= target; sum++) {
                int notTake = prev[sum];         
                int take = 0;
                if (nums[i] <= sum)
                    take = prev[sum - nums[i]];

                curr[sum] = take + notTake;
            }
            prev = curr;
        }
        return prev[target];
    }

    int f1(vector<int>& nums, int d) {
        int sum = 0;
        for (int x : nums) sum += x;

        if ((sum - d) < 0 || (sum - d) % 2 != 0)
            return 0;                           

        return f(nums, (sum - d) / 2);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return f1(nums, target);
    }
};
