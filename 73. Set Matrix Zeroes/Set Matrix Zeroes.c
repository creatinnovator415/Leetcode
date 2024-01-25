void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int row;
    int col;
    int index;
    int base_row;
    int base_col;
    
    base_row = INT_MAX;
    base_col = INT_MAX;
    
    for(row = 0; row < matrixSize ; row++)
    {
        for(col = 0; col < matrixColSize[row]; col++)
        {
            if( matrix[row][col] == 0 && 
                (base_row == INT_MAX || base_row != row) &&
                (base_col == INT_MAX || base_col != col)
              )
            {
                if(base_row == INT_MAX)
                {
                    base_row = row;
                    base_col = col; 
                    for(index = 0; index < matrixColSize[row]; index++)
                    {
                        matrix[base_row][index] = ( matrix[base_row][index] == 0 ) ? 1 : 0;//first zero have zero
                    }
                    
                    for(index = 0; index < matrixSize; index++)
                    {
                        matrix[index][base_col] = ( matrix[index][base_col] == 0 ) ? 1 : 0;//first zero have zero
                    }
                }
                
                matrix[base_row][col] = 1;
                matrix[row][base_col] = 1;
                
            }
        }
    }
    
    if(base_col != INT_MAX)
    {
        for(row = 0; row < matrixSize ; row++)
        {
            if(matrix[row][base_col] == 1)
            {
                for(col = 0; col < matrixColSize[row]; col++)
                {
                    if(row == base_row || col == base_col)////first zero need to judge overwrite
                    {
                       if( matrix[row][col] != 1 )//first zero don't overwrite reset flag
                        {
                           matrix[row][col] = 0; 
                        } 
                    }else//just write
                    {
                        matrix[row][col] = 0; 
                    }
                    

                }
            }
        }
    }
    
    if(base_row != INT_MAX)
    {
        for(col = 0; col < matrixColSize[0] ; col++)
        {
            if(matrix[base_row][col] == 1)
            {
                for(row = 0; row < matrixSize; row++)
                {
                    matrix[row][col] = 0;
                }
            }
        }
    }
}