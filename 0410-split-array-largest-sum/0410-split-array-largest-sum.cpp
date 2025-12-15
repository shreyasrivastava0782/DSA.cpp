class Solution {
public:

    bool isValid(vector<int>&nums,int k,int maxAllowed){
        int painter=1;
        int walls=0;

        int n=nums.size();

        for(int i=0;i<n;i++){
            if(nums[i]>maxAllowed){
                return false;
            }

            if(walls+nums[i]<= maxAllowed){
                walls+=nums[i];
            }
            else{
                painter++;
                walls=nums[i];
            }
        }
        return painter>k?false:true;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }

        int ans=-1;

        int st=0;
        int end=sum;

        while(st <= end){
            int mid=st+(end-st)/2;

            if(isValid(nums,k,mid)){
                ans=mid;
                end=mid-1;
            }
            else{
                st=mid+1;
            }
        }
        return ans;
    }
};