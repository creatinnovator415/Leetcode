/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int left;
    int right;
    int middle;
    int* result;
    
    
    left = 0;
    right = numsSize - 1;
    result = (int*)malloc(sizeof(int)*2);
    result[0] = -1;
    result[1] = -1;
    
    while(left <= right)
    {
        middle = left +  (right - left)/ 2;
        
        if( (nums[middle] == target) && 
            ( ( ( middle > 0) && ( nums[middle - 1] != target) ) ||
              ( middle == 0)
            ) 
           )
        {
            result[0] = middle;
            break;
        }else if( nums[middle] >= target )
        {
            
            right = middle - 1;
        }else
        {
            
            left = middle + 1;
        }
    }
       
    left = (result[0] != -1) ? result[0] : 0;
    right = numsSize - 1;
           
    while(left <=  right)
    {
        middle = left +  (right - left)/ 2;
        
        if( (nums[middle] == target) && 
            ( ( (middle < (numsSize-1)) && ( nums[middle + 1] != target) ) ||
              ( middle == (numsSize-1))
            )
           )
        {
            result[1] = middle;
            break;
        }else if( nums[middle] <= target )
        {
            left = middle + 1;
        }else 
        {
            right = middle - 1;
        } 
    }
       
    *returnSize = 2;
    return result;
}