class Solution {
public:
    int bottomUp(int m, int n, vector<vector<int>> &dp)
    {
        if(m==0 || n==0)
            return 1;
        
        if(dp[m][n] != -1)
            return dp[m][n];
        
        int right = bottomUp(m-1, n, dp);
        int down = bottomUp(m, n-1, dp);
        
        return dp[m][n] = right+down ;
    }
    
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return bottomUp(m-1, n-1, dp);
        
        
        
//         Top-Down Approach
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(i==0 || j==0)
                    dp[i][j] = 1;
        
        for(int i=1; i<m; i++)
            for(int j=1; j<n; j++)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        
        return dp[m-1][n-1];
    }
};