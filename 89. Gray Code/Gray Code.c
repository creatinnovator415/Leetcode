/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* grayCode(int n, int* returnSize) {
    int count;
    int index;
    int mapping_index;
    int* result;
    
    *returnSize = 1 << n;
    result = (int*)malloc(sizeof(int) * *returnSize);
    result[0] = 0;
    
    for(index = 0; index < n; index++)
    {
        count = 1 << index;
        
        for(mapping_index = 0; mapping_index < count; mapping_index++)
        {
            result[count + mapping_index] = result[count - mapping_index - 1] + (1 << index);
        }
    }
    
    
    return result;
}