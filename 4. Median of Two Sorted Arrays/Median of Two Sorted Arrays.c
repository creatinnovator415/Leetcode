double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){

    int one_index;
    int two_index;
    int three_index;
    int tmp;
    int record_index;
    int record_num[2];
    int two;
    int middle;
    
 
    one_index = 0;
    two_index = 0;
    three_index = 0;
    middle = nums1Size + nums2Size;
    two = (middle % 2) ? 1 : 2;
    middle = (two == 2) ? (middle/2 -1) : middle/2;
    record_index = 0;
    
    
    while(true)
    {
        if( (one_index < nums1Size) && (two_index < nums2Size) )
        {
            if(nums1[one_index] < nums2[two_index])
            {
                tmp = nums1[one_index];
                one_index++;
            }else
            {
                tmp = nums2[two_index];
                two_index++;
            }
            
            
        }else if(one_index < nums1Size)
        {
            tmp = nums1[one_index];
            one_index++;
        }else if(two_index < nums2Size)
        {
            tmp = nums2[two_index];
            two_index++;
        }
        
        
        
        if(three_index == middle)
        {
            record_num[record_index] = tmp;
            record_index++;
            middle++;
            if(two == record_index)
            {
                break;
            }
        }
        
        three_index++;
    }
    
    return (two == 2) ? 
           (((double)record_num[0] + record_num[1]) /2) :
            record_num[0];
}