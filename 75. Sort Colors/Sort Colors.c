void sortColors(int* nums, int numsSize) {
    int l;
    int r;
    int index;
    int tmp;
    
    l = 0;
    r = numsSize - 1;
    index = 0;
    
    while(index <= r)
    {
        if(nums[index] == 0)
        {
            tmp = nums[index];
            nums[index] = nums[l];
            nums[l] = tmp;
            if(index == l)
            {
                index++;
            }
            l++;
        }else if(nums[index] == 2)
        {
            tmp = nums[index];
            nums[index] = nums[r];
            nums[r] = tmp;
            if(index == r)
            {
                index++;
            }
            r--;
        }else
        {
            index++;
        }

    }
    
    
    while(l<r)
    {
       nums[l] = 1;
       l++;
    }
    
}