class Solution {
public:

    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();

        vector<int>left(n,0);
        vector<int>right(n,0);
        stack<int>st;

        for(int i=n-1;i>=0;i--){
            while(st.size()>0 && heights[st.top()]>=heights[i]){
                st.pop();
            }
            right[i]=st.empty()?n:st.top();

            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }

        for(int i=0;i<n;i++){
            while(st.size()>0 && heights[st.top()]>=heights[i]){
                st.pop();
            }
            left[i]=st.empty()?-1:st.top();

            st.push(i);
        }

        int ans;
        for(int i=0;i<n;i++){
            int currArea=heights[i]*(right[i]-left[i]-1);
            ans=max(ans,currArea);
        }

        return ans;
        
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
           int n=matrix.size();
           int m=matrix[0].size();
           vector<int>heights(m,0);
           int ans=0;

           for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='0'){
                    heights[j]=0;
                }
                else{
                    heights[j]++;
                }
            }
            ans=max(ans,largestRectangleArea(heights));
           }
           return ans;
    }
};