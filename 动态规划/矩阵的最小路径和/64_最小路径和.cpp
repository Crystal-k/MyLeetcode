//方法一 
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        if(m==0) return 0;

        int n=grid[0].size();
        if(n==0) return 0;

        vector<vector<int>> dp(m,vector<int>(n));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0&&j==0){
                    dp[i][j]=grid[i][j];
                }else if(i==0){
                    dp[i][j]=dp[i][j-1]+grid[i][j];
                }else if(j==0){
                    dp[i][j]=dp[i-1][j]+grid[i][j];
                }else{
                    dp[i][j]=min(dp[i][j-1],dp[i-1][j])+grid[i][j];
                }
            }
        }s
        return dp[m-1][n-1];
    }
};

//方法二（优化） 
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        if(m==0) return 0;

        int n=grid[0].size();
        if(n==0) return 0;

        vector<int> dp(n,0);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(j==0){
                    dp[j]=dp[j];
                }else if(i==0){
                    dp[j]=dp[j-1];
                }else{
                    dp[j]=min(dp[j],dp[j-1]);
                }

                dp[j]+=grid[i][j];
            }
        }
        return dp[n-1];
    }
};
