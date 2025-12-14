class Solution {
public:

    int sumOfDiv(vector<int>&nums,int div){
        int sum=0;
        int n=nums.size();

        for(int i=0;i<n;i++){
            sum=sum+ceil((double)(nums[i])/(double)(div));
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();

        int l=1;
        int h=*max_element(begin(nums),end(nums));
        int ans=-1;

        while(l<=h){
            int mid=l+(h-l)/2;

            if(sumOfDiv(nums,mid)<=threshold){
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};