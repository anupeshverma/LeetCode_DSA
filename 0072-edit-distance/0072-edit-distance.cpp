class Solution {
    private:
    int lcs(string s1, string s2, int n, int m)
    {
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        
//         If s1 is nul, we have to add m words
        for (int i = 1; i <= n; i++)
            dp[i][0] = i; 
//      If s2 is null, we have to delete n words;
        for (int j = 1; j <= m; j++)
            dp[0][j] = j; 
        
        for(int i=1; i<=n; i++)
             for(int j=1; j<=m; j++)
                 if(s1[i-1] == s2[j-1])
                     dp[i][j] = dp[i-1][j-1];
                 else
                     dp[i][j] = 1+min(min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1]);
        return dp[n][m];
        
    }
public:
    int minDistance(string word1, string word2) {
        
        int n = word1.size();
        int m = word2.size();
        
        return lcs(word1, word2, n, m);
    }
};