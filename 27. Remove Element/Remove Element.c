int removeElement(int* nums, int numsSize, int val) {
    int insert_index;
    int cmp_index;

    insert_index = 0;
    cmp_index = 0;
    
    while(cmp_index < numsSize)
    {
        if(nums[cmp_index] != val)
        {
           nums[insert_index]  = nums[cmp_index];
           insert_index++;
        }
        cmp_index++;
    }
    
    return insert_index;
}