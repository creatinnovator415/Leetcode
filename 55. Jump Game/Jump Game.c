bool canJump(int* nums, int numsSize) {
    int index;
    int reach;
    
    
    reach = 0;
    
    for(index = 0; index < numsSize; index++)
    {
        if( (index > reach) || (reach >= (numsSize -1)) )
        {
            break;
        }
        
        if( (index+nums[index]) > reach )
        {
            reach = index+nums[index];
        }
        
    }
    
    return reach >= ( numsSize -1 );
}