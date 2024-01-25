
void diag_reverse_matrix(int** matrix, int matrixSize, int* matrixColSize)
{   
    int row;
    int column;
    int tmp;
        
    
    column = 0;
    
    while(column < matrixColSize[0])
    {
        row = matrixSize - 1;
        while(row >= 0)
        {
            if(row > column)
            {
                tmp = matrix[row][column];
                matrix[row][column] = matrix[column][row];
                matrix[column][row] = tmp;
            }
            
            row--;
        }
        column++;
    }
    
}

void col_reverse_matrix(int** matrix, int matrixSize, int* matrixColSize)
{
    int left;
    int right;
    int* tmp;
    
    left = 0;
    right = matrixColSize[0]-1;
    
    while(left < right)
    {
        tmp = matrix[left];
        matrix[left] = matrix[right];
        matrix[right] = tmp;
        left++;
        right--;
    }
    
}

void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    col_reverse_matrix(matrix, matrixSize, matrixColSize);
    diag_reverse_matrix(matrix, matrixSize, matrixColSize);
}