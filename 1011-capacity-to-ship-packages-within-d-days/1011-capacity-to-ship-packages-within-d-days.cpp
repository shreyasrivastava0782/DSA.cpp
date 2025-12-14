class Solution {
public:

    int findDays(vector<int>&weights,int cap){
        int days=1;
        int load=0;

        for(int i=0;i<weights.size();i++){
            if(weights[i]+load > cap){
                days+=1;
                load=weights[i];
            }
            else{
                load+=weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();

        int l=*max_element(begin(weights),end(weights));
        int sum=0;

        for(int i=0;i<weights.size();i++){
            sum+=weights[i];
        }
        int h=sum;

        while(l<=h){
            int mid=l+(h-l)/2;

            int noOfDays=findDays(weights,mid);
            if(noOfDays <= days){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};