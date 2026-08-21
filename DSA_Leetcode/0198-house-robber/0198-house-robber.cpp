class Solution {
public:
    int fun(vector<int>& nums,int n, int i, int free_will,vector<vector<int>>&dp){
        if(i==n) return 0;

        if( dp[i][free_will] != -1 ) return dp[i][free_will];

        if(free_will==0){
            return dp[i][free_will] = fun(nums,n,i+1,1,dp);
        }

        int c1= nums[i] + fun(nums,n,i+1,0,dp);
        int c2= fun(nums, n, i+1, 1,dp);
        return dp[i][free_will] = max(c1,c2);

    }
    int rob(vector<int>& nums) {
        int n= nums.size();
        vector<vector<int>>dp(n);

        for(int i=0;i<n;i++){
            vector<int>t(2,-1);
            dp[i]=t;
        }
        return fun(nums,n,0,1,dp);
        
    }
};