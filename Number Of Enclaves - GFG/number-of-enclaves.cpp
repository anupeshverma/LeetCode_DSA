//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>visited(n, vector<int>(m, 0));
        queue<pair<int,int>>q;
        
        for(int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                if(i==0 || j==0 || i==n-1 || j==m-1)
                    if(grid[i][j] == 1)
                    {
                        visited[i][j] = 1;
                        q.push({i, j});
                    }
                    
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            int drow[] = {-1,0,1,0};
            int dcol[] = {0,1,0,-1};
            
            for(int i=0; i<4; i++)
            {
                int newRow = row+drow[i];
                int newCol = col+dcol[i];
                
                if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && grid[newRow][newCol]==1 && !visited[newRow][newCol])
                {
                    visited[newRow][newCol]=1;
                    q.push({newRow, newCol});
                }
            }
        }
        
        int ans = 0;
        for(int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                if(grid[i][j] == 1 && !visited[i][j])
                   ans++;
        
        return ans;   
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends