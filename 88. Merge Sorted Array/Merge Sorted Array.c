void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int index;
    int l_index;
    int r_index;
    int count;
    int tmp;
    
    l_index = m-1;
    r_index = n-1;
    index = m+n-1;
    

    while(index >= 0)
    {
        if( (l_index >= 0) && (r_index >= 0) )
        {
            if(nums1[l_index] > nums2[r_index])
            {
               nums1[index] = nums1[l_index];
               l_index--;
            }else
            {
               nums1[index] = nums2[r_index];
               r_index--;
            }
           
        }else if(l_index >= 0)
        {
            nums1[index] = nums1[l_index];
            l_index--;
        }else if(r_index >= 0)
        {
            nums1[index] = nums2[r_index];
            r_index--;
        }
        
        index--;
    }
    
}