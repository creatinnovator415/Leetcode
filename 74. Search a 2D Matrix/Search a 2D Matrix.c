bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int l;
    int r;
    int m;
    int row;
    int col;
    
    l = 0;
    r = matrixSize -1;
    row = INT_MIN;
    col = INT_MIN;
    
    while(l<=r)
    {
        m = l + (r - l)/2;
        
        if( (matrix[m][0] > target && 0 == m)|| 
            (matrix[m][0] <= target && (matrixSize -1) == m)||
            (matrix[m][0] <= target && target < matrix[m+1][0])
          )
        {
            row = m;
            break;
        }else if( matrix[m][0] > target )
        {
            r = m-1;
        }else
        {
            l=m+1;
        }
    }
    
    l = 0;
    r = matrixColSize[0] - 1;
   
    while(l<=r)
    {
        m = l + (r - l)/2;
        
        if( matrix[row][m] == target)
        {
            col = m;
            break;
        }else if( matrix[row][m] > target )
        {
            r = m-1;
        }else
        {
            l=m+1;
        }
    }

    return (col != INT_MIN) ? true : false;
    
}