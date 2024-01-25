int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize) {
    int row_index;
    int col_index;
    int* dp;
    
    
    dp = (int*)malloc(sizeof(int)*obstacleGridColSize[0]); 
    

    dp[0] = obstacleGrid[0][0] ? 0:1;

    for(col_index = 1; col_index < obstacleGridColSize[0]; col_index++)
    {
        if((0==dp[col_index-1]) || (1==obstacleGrid[0][col_index]))
        {
            dp[col_index] = 0;
        }else
        {
            dp[col_index] = 1;
        }
        
    }
    
    for(row_index = 1; row_index < obstacleGridSize; row_index++)
    {
        for(col_index = 0; col_index < obstacleGridColSize[row_index]; col_index++)
        {
             if(obstacleGrid[row_index][col_index])
            {
                dp[col_index] = 0;
            }else
            {
                if(col_index > 0)
                {
                      dp[col_index] += dp[col_index - 1];  
                }
                
            }
            
        }
    }
    
    return dp[obstacleGridColSize[0]-1];

}