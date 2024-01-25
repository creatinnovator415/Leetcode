int minPathSum(int** grid, int gridSize, int* gridColSize) {
    int row_index;
    int col_index;
    int* dp;
    
    dp = (int*)malloc(sizeof(int)*gridColSize[0]); 
    
    for(row_index = 0; row_index < gridSize; row_index++)
    {
        for(col_index = 0; col_index < gridColSize[0]; col_index++)
        {
           if(0 == row_index)
           {
               dp[col_index] = (0 == col_index) ? grid[row_index][col_index] : dp[col_index-1] + grid[row_index][col_index];
           }else
           {

               if( ( 0 == col_index ) ||
                   ( (dp[col_index] + grid[row_index][col_index]) < (dp[col_index-1] + grid[row_index][col_index]) )
                 )
               {
                   dp[col_index] = dp[col_index] + grid[row_index][col_index];
               }else
               {
                   dp[col_index] = dp[col_index-1] + grid[row_index][col_index];
               }
               
           }
        }
    }
    
    return dp[gridColSize[0]-1];

}