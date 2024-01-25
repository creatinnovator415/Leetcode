int jump(int* nums, int numsSize) {
    int steps;
    int next_index;
    int index;
    int max;
    
    steps = 0;
    max = 0;
    next_index = 0;
    
    
    while(next_index < (numsSize - 1))
    {
        max = INT_MIN;
        
        for(index = 1; index <= nums[next_index]; index++)
        {
            if(next_index+index < (numsSize - 1))
            {
                if( max == INT_MIN || (next_index+index+nums[next_index+index]) > (max+nums[max]) )
                {
                    max = next_index+index;
                }
            }else
            {
                max = numsSize - 1;
                break;
            }
        }

        next_index = max;
        steps++;
    }
    
    
    return steps;
}