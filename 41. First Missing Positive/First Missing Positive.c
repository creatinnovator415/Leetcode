void swap(int* a, int* b)
{
    int tmp;
    
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int firstMissingPositive(int* nums, int numsSize)
{
    int min_positive;
    int min_positive_pos;
    int index;

    
    min_positive = INT_MAX;
    
    for(index = 0; index < numsSize; index++)
    {
        while(nums[index] > 0 && nums[index] <= numsSize && nums[nums[index] - 1] != nums[index])
        {
            swap(&nums[index], &nums[nums[index] - 1]);
        }
    }
           
    for(index = 0; index < numsSize; index++)
    {
        if( (index+1) != nums[index] )
        {
            break;
        }
    }
    
    return (index+1);

}