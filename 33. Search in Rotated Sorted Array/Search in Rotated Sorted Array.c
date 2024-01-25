int get_map_pos(int pos, int offset,int numsSize)
{ 
    if(pos >= (numsSize - offset))
    {
        return (pos+offset) % numsSize;
    }else
    {
        return pos+offset;
    }
}

int get_next(int pos, int numsSize)
{ 
    return (pos+1) % numsSize;
}

int get_prev(int pos,int numsSize)
{ 
    return ( (pos-1) >= 0 ) ? (pos-1) : (numsSize-1);
}

int search(int* nums, int numsSize, int target){
    int left;
    int middle;
    int right;
    int offset;
    
    left = 0;
    right = numsSize-1;
    while(left<=right)
    {
        middle = left + (right - left)/ 2;
        if(nums[middle] == target)
        {
            return middle;
        }else if (nums[middle] < nums[right]) 
        {
            if (nums[middle] < target && nums[right] >= target)
            {
                left = middle + 1;
            }else 
            {
                right = middle - 1;
            }
        } else 
        {
            if (nums[left] <= target && nums[middle] > target)
            {
                right = middle - 1;
            }
            else 
            {
                left = middle + 1;
            }
        }
    }
    
    return -1;
 
}