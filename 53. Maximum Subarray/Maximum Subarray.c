int maxSubArray(int* nums, int numsSize) {
    int index;
    int max_sum;
    int current_max_sum;
    
    
    max_sum = nums[0];
    current_max_sum = nums[0];
    
    for(index = 1; index < numsSize; index++)
    {
        if(nums[index] > current_max_sum + nums[index])
        {
            current_max_sum = nums[index];
        }else
        {
            current_max_sum += nums[index];
        }
        
       if(current_max_sum > max_sum)
       {
            max_sum = current_max_sum;
       }    
    }
    
    return max_sum;
}