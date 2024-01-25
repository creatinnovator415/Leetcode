int uniquePaths(int m, int n){
    int row_index;
    int col_index;
    int* dp;
    
    dp = (int*)malloc(sizeof(int)*n); 
    
    for(col_index = 0; col_index < n; col_index++)
    {
        dp[col_index] = 1;
    }
    
    for(row_index = 1; row_index < m; row_index++)
    {
        for(col_index = 1; col_index < n; col_index++)
        {
            dp[col_index] += dp[col_index - 1];
        }
    }
    
    return dp[n-1];

}