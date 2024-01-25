

int myAtoi(char * s){
    char* s_ptr;
    int number;
    bool check;
    int sign;

    
    number = 0;
    s_ptr = s;
    sign = 0;
    
    while(*s_ptr != '\0')
    {   
        if( ( ( '0' <= *s_ptr ) && ( *s_ptr <= '9' ) ) || 
            (' ' == *s_ptr) ||
            ('+' == *s_ptr) ||
            ('-' == *s_ptr) ||
            ('.' == *s_ptr)
           )
        {
            if(  ('+' == *s_ptr) || ('-' == *s_ptr)  )
            {
                if(sign != 0)
                {
                    break;
                }
                
                sign = ('-' == *s_ptr) ? -1 : 1;
            }else if(  *s_ptr == ' ' )
            {
                if(sign != 0)
                {
                    break;
                }
            }else if(  *s_ptr == '.' )
            {
                break;
            }else if( ( '0' <= *s_ptr ) && ( *s_ptr <= '9' ) )
            {
                 if(sign == 0)
                 {
                     sign = 1;
                 }

                if( (number > (INT_MAX / 10)) || 
                    (number == (INT_MAX / 10) && *s_ptr - '0' > 7) 
                  )
                {
                    return (sign == -1) ?  INT_MIN : INT_MAX;
                }

                number = number*10 + (*s_ptr - '0');

            }

        }
        else if( 0 == number )
        {
            break;
        }else
        {
            if(sign != 0)
            {
                break;
            }
        }

        s_ptr++;   
    }
    
    return sign*number;
}