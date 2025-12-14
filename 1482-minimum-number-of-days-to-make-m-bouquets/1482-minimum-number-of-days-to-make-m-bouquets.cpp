class Solution {
public:

    int canMakeBouq(vector<int>&bloomDay,int mid,int k){
        int bouqCount=0;
        int consecutiveCount=0;

        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid){
                consecutiveCount++;
            }
            else{
                consecutiveCount=0;
            }
            if(consecutiveCount==k){
                bouqCount++;
                consecutiveCount=0;
            }
        }
        return bouqCount;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        int l=0;
        int r=*max_element(begin(bloomDay),end(bloomDay));

        int minDays=-1;
        while(l<=r){
            int mid=l+(r-l)/2;

            if(canMakeBouq(bloomDay,mid,k)>=m){
                minDays=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return minDays;
    }
};