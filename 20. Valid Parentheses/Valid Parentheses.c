bool isValid(char * s){
    int str_len;
    int str_index;
    int stack_ptr;
    char* stack;
        
    str_len = strlen(s);
    stack = (char*)malloc(sizeof(char)*str_len);
    stack_ptr = -1;
    str_index = 0;
    
    
    for(str_index = 0; str_index < str_len; str_index++)
    {
        if(stack_ptr != -1)
        {
            if( (stack[stack_ptr] == '(' && s[str_index] == ')') ||
                (stack[stack_ptr] == '[' && s[str_index] == ']') ||
                (stack[stack_ptr] == '{' && s[str_index] == '}') 
              )
            {
                stack_ptr--;
                continue;
            }else if(s[str_index] == ')' || s[str_index] == ']' || s[str_index] == '}')
            {
                break;
            }
        }else
        {
            if( s[str_index] == ')' || s[str_index] == ']' || s[str_index] == '}')
            {
                break;
            }
        }
            
        stack_ptr++;
        stack[stack_ptr] = s[str_index];
    }
    
    return ( (str_index < str_len) || (stack_ptr != -1) ) ? false : true;
}