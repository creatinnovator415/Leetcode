int maxArea(int* height, int heightSize){
    int left;
    int right;
    int max;
    int tmp;
    
    
    left = 0;
    right = heightSize - 1;
    max = 0;
    
    
    while(left < right)
    {
        
        tmp = (height[left] > height[right]) ? height[right] : height[left];
        tmp *= (right - left);
        
        if( tmp > max )
        {
            max = tmp;
        }
        
        if(height[left] > height[right])
        {
            right--;
        }else
        {
            left++;
        }
        
    }
    
    return max;

}