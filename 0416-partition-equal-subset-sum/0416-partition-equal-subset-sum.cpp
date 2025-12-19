class Solution {
public:

    bool f1(int k,vector<int>&nums){
        int n=nums.size();
        vector<bool>prev(k+1,0),curr(k+1,0);
        prev[0]=curr[0]=true;
          if(nums[0] <= k) prev[nums[0]] = true;

        for(int i=1;i<n;i++){
            for(int tar=1;tar<=k;tar++){
                bool notTake=prev[tar];
                bool take=false;
                if(nums[i]<=tar) take=prev[tar-nums[i]];
                curr[tar]=take || notTake;
            }
            prev=curr;
        }
        return prev[k];
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;

        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2 !=0 ){
            return false;
        }

        int tar=sum/2;

        return (f1(tar,nums));
    }
};