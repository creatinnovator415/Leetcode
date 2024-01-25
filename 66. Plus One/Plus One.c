/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int index;
    int overflow;
    int* result;
    int result_index;
    int total_count;
    
    index = digitsSize - 1;
    overflow = 1;
    total_count = digitsSize+1;
    result = (int*)malloc(sizeof(int)*total_count);
    *returnSize = 0;
    
    for(index = digitsSize - 1; index >= 0; index--)
    {
        digits[index] += overflow;
        overflow = digits[index] / 10;
        digits[index] %= 10;
        result[total_count - *returnSize - 1] = digits[index];
        (*returnSize)++;
    }
    
    if(overflow)
    {
        result[total_count - *returnSize - 1] = overflow;
        (*returnSize)++;
        return  &result[0];
    }else
    {
        return  &result[1];
    }
}