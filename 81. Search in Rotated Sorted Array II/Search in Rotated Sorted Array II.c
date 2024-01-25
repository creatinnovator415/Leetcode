//Solve tartget on non decreasing case
//Solve target in decreasing and non decreasing case
//Solve unknown case
bool search(int* nums, int numsSize, int target) {
    int l;
    int r;
    int m;
    bool result;
    
    l = 0;
    r = numsSize - 1;
    result = false;

    while(l<=r)
    {
        m = l + (r-l)/2;

        if(nums[m] == target)
        {
            result = true;
            break;
        }if (nums[m] < nums[r]) 
        {
            if (nums[m] < target && nums[r] >= target) 
            {
                l = m + 1;
            }
            else 
            {
                r = m - 1;
            }
        } else if (nums[m] > nums[r])
        {
            if (nums[l] <= target && nums[m] > target) 
            {
                r = m - 1;
            }
            else 
            {
                l = m + 1;
            }
        }
        else
        {
            r--;
        }
    }
    
    return result;
    
}