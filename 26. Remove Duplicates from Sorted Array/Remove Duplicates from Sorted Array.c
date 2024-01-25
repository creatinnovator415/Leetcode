int removeDuplicates(int* nums, int numsSize) {
    int left;
    int right;
    int num_index;
    int num;
    int index;
    
    num = nums[0];
    num_index = 0;
    
    for(index = 0; index < numsSize; index++)
    {
        if(num <= nums[index])
        {
            nums[num_index] = nums[index];
            num = nums[index]+1;
            num_index++;
        }
    }
    
    return num_index;
    
}