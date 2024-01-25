int mySqrt(int x) {
    int64_t left;
    int64_t right;
    int64_t middle;
    
    left = 0;
    right = x;
    
    while(left <= right)
    {
       middle = left + (right - left)/2;
       
       if( (middle*middle) <= x && x < (middle +1)*(middle +1) )
       {
            break;    
       }else if((middle +1)*(middle +1) <= x)
       {
           left = middle +1;
       }else 
       {
           right = middle - 1;
       }
    }
    
    return middle;
}