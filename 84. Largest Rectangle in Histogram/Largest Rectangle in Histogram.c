
#define ALLOC_LENGTH            (100000)

int largestRectangleArea(int* heights, int heightsSize){
    int max;
    int area;
    int* stack;
    int stack_ptr;
    int index;
    int cur_height;
    
    stack_ptr = -1;
    stack = (int*)malloc(sizeof(int)*ALLOC_LENGTH);
    max = 0;
    
    for(index = 0; index < (heightsSize+1); index++)
    {
        cur_height = (index == heightsSize) ? 0 : heights[index];
        
        if( (-1 == stack_ptr) || (cur_height > heights[stack[stack_ptr]]) )
        {
            stack_ptr++;
            stack[stack_ptr] = index;
        }else
        {
            area = stack[stack_ptr];
            stack_ptr--;
            area =  ((stack_ptr == -1) ? index : (index - stack[stack_ptr]-1) ) * heights[area];
            max = (area > max) ? area : max;
            
            index--;
        }
        
    }

    return max;

}