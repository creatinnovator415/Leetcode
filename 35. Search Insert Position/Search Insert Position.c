int searchInsert(int* nums, int numsSize, int target){
    int left;
    int right;
    int middle;
    
    
    left = 0;
    right = numsSize - 1;
    
    while(left<=right)
    {
        middle = left + (right - left)/2;
        if(  ( ( nums[middle] <= target ) &&
               (  ( middle == (numsSize-1) ) ||
                  ( ( (middle+1) < numsSize ) && 
                    ( nums[middle+1] > target ) 
                  )  
               ) 
             ) ||
             ( ( nums[middle] >= target ) &&
               ( (middle == 0) || 
                  ( ( (middle-1) >= 0 ) && 
                    (nums[middle-1] < target) 
                   )  
                  
                 )
              )
             
           )
        {
            return (nums[middle] < target) ? middle+1 : middle;
        }else if(nums[middle] > target)
        {
            right = middle - 1;
        }else
        {
            left = middle + 1;
        }
    }
    
    return -1;

}