class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(),n= word2.length();
        vector<vector<int>>dp(m+1,vector<int>(n+1, -1)); // m are rows and n are columns and initialized by -1;
        for(int i=0; i<=m; i++){ //run loop for given rows and columns;
            for(int j=0; j<=n; j++){
               if(i==0) dp[i][j]=j;
               if(j==0) dp[i][j] = i;
            }
        }

        for(int i=1; i<=m;i++){ //run from 1st to last
            for(int j=1; j<=n;j++){
                  if(word1[i-1]==word2[j-1]){
                      dp[i][j] = dp[i-1][j-1]; //return the same operation as before
                  }
                  else{
                    dp[i][j] = 1+min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]); //min of del ,insert or update operation and 1 default operation in it
                  }
            }
        }
        return dp[m][n]; //return last column or total operations
    }
};
