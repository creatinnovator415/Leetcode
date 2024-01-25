#define ALLOC_LENGTH            (2)


int longestValidParentheses(char * s){
    int* stack;
    int stack_ptr;
    int s_ptr;
    int max;
    int alloc_length;

    alloc_length = ALLOC_LENGTH;
    stack = (int*)malloc(sizeof(int)*alloc_length);
    stack_ptr = -1;
    max = 0;
    stack_ptr++;
    stack[stack_ptr] = -1;
    
    while(s[s_ptr] != '\0')
    {
        if(s[s_ptr] == '(')
        {   
            stack_ptr++;
            stack[stack_ptr] = s_ptr;
            if(stack_ptr == (alloc_length - 1))
            {
                alloc_length*=2;
                stack = (int*)realloc(stack, sizeof(int)*alloc_length);
            }
        }else 
        {
            stack_ptr--;
            
            if(stack_ptr == -1)
            {
                stack_ptr++;
                stack[stack_ptr] = s_ptr;
                if(stack_ptr == (alloc_length - 1))
                {
                    alloc_length*=2;
                    stack = (int*)realloc(stack, sizeof(int)*alloc_length);
                }
            }else
            {
                
                if(max < (s_ptr - stack[stack_ptr]))
                {
                    max = (s_ptr - stack[stack_ptr]);
                }
            }
        }
       
        s_ptr++;
    }
    


    return max;
}