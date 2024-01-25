#define GET_MIN(x,y)            (((x)>(y))? (y):(x))

int trap(int* height, int heightSize) {
    int* stack;
    int stack_ptr;
    int max_water;
    int top;
    int index;
    int cal_height;
    int cal_length;
    
    stack = (int*)malloc(sizeof(int)*heightSize);
    stack_ptr = -1;
    max_water = 0;
    
    for(index = 0; index < heightSize; index++)
    {
        
        if( -1 != stack_ptr)
        {
            while(stack_ptr != -1 && height[index] > height[stack[stack_ptr]])
            {
                top = stack[stack_ptr];
                stack_ptr--;
                if(stack_ptr == -1)
                {
                    break;
                }
                
                cal_height = GET_MIN(height[stack[stack_ptr]],height[index])-height[top];
                cal_length = index - stack[stack_ptr] - 1;
                
                max_water += cal_length * cal_height;
            }
        }
        
        stack_ptr++;
        stack[stack_ptr] = index;
    }
    
    return max_water;
}