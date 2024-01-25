#define ALLOC_LENGTH            (1000)

char * simplifyPath(char * path){

    char* path_stack;
    int   path_stack_ptr;
    char  mark_stack[2];
    int   mark_stack_ptr;
    int   mark_index;
    int   alloc_length;

    
    
    path_stack_ptr = -1;
    mark_stack_ptr = -1;
    alloc_length = ALLOC_LENGTH;
    path_stack = (char *)malloc(sizeof(char) * alloc_length);

    
    while(*path != '\0' )
    {
        switch(*path)
        {
            case '/':
                
                if( (path_stack_ptr == -1) ||
                    (path_stack[path_stack_ptr] != '/')
                  )
                {
                   path_stack_ptr++;
                   path_stack[path_stack_ptr] = '/';

                }
              
                break;
            case '.':
                
                if(mark_stack_ptr < 1)
                {

                        mark_stack_ptr++;
                        mark_stack[mark_stack_ptr] = '.';

                    
                }else
                {
                    mark_index = 0;
                        
                    while(mark_index < 3)
                    {
                        path_stack_ptr++;
                        path_stack[path_stack_ptr] =  '.';
                        mark_index++;
                    }
                    
                    mark_stack_ptr = -1;
                }
                break;
            default:

                while(mark_stack_ptr>=0)
                {
                    path_stack_ptr++;
                    path_stack[path_stack_ptr] = '.';
                    mark_stack_ptr--;
                }
                path_stack_ptr++;
                path_stack[path_stack_ptr] = *path;
                break;
        }
        
        path++;
        
        if(*path == '/' || *path == '\0')
        {
            if(path_stack[path_stack_ptr] != '/')
            {
                while(mark_stack_ptr >= 0)
                {
                    path_stack_ptr++;
                    path_stack[path_stack_ptr] = '.';
                    mark_stack_ptr--;
                }
            }
            if( 1 == mark_stack_ptr)
            {
                if(path_stack_ptr > 0)
                {
                    path_stack_ptr--;
                    while(path_stack[path_stack_ptr] != '/')
                    {
                        path_stack_ptr--;
                    }

                }
            }
            mark_stack_ptr = -1;
        }
    }
    
    if( (0 < path_stack_ptr) && 
        (path_stack[path_stack_ptr] == '/')
      )
    {
        path_stack[path_stack_ptr] = '\0';
    }else
    {
        path_stack_ptr++;
        path_stack[path_stack_ptr] = '\0';
    }
    
    return path_stack;
}