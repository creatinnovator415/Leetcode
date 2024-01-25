void nextPermutation(int* nums, int numsSize){
    int index;
    int last_num;
    int swap_index;
    int tmp;
    int left;
    int right;
    
    last_num = INT_MIN;
    
    for(index = numsSize-1; index >= 0; index--)
    {
        if( (INT_MIN == last_num) )
        {
            last_num = nums[index];
        }else
        {
            if(last_num > nums[index])
            {
                break;
            }else
            {
                last_num = nums[index];
            }
        }

    }
    
    swap_index = index;
   
    if(swap_index >= 0)
    {
        for(index = numsSize-1; index >= 0; index--)
        {
            if(nums[index] > nums[swap_index])
            {
                tmp = nums[index];
                nums[index] = nums[swap_index];
                nums[swap_index] = tmp;
                break;
            }else if(swap_index >= index)
            {
                break;
            }
        }

    }
    left = swap_index+1;
    right = numsSize-1;
    
    while(left < right)
    {
        tmp = nums[left];
        nums[left] = nums[right];
        nums[right] = tmp; 
        left++;
        right--;
    }
    

}