bool isSignChar(char s)
{
    if( (s == '+') || (s == '-') )
    {
        return true;
    }
    return false;
}

char* skipSpace(char* s)
{
    while(*s == ' ')
    {
        s++;
    }
    
    return s;
}

bool isDigit(char s)
{
    if( ('0' <= s) && (s <= '9') )
    {
        return true;
    }
    
    return false;
}

bool isEe(char s)
{
    if( (s == 'E') || (s == 'e') )
    {
        return true;
    }
    
    return false;
}

bool isDot(char s)
{
    if( s == '.' )
    {
        return true;
    }
    
    return false;
}

bool isNumber(char* s) {
    int dot_count;
    int e_count;
    int e_count_h;
    int e_count_e;
    int d_count_h;
    int d_count_e;
    int sign;
    bool result;
    
    dot_count = 0;
    e_count = 0; 
    s = skipSpace(s);
    sign = INT_MAX;
    e_count_h = INT_MAX;
    e_count_e = INT_MAX;
    d_count_h = INT_MAX;
    d_count_e = INT_MAX;
    result = true;
    
    if(strlen(s) == 1)
    {
        if( isSignChar(*s) || isEe(*s) || isDot(*s))
        {
            result = false;
        }
    }else
    {
        while(*s != '\0')
        {
            if(isSignChar(*s))
            {
                if(sign == INT_MAX)
                {
                    sign = (*s == '+') ? 1:-1;
                }else
                {
                    result = false;
                    break;
                }

            }else
            {
                sign = 1;

                if( isDot(*s) )
                {
                   if(e_count == 0 && dot_count == 0)
                   {
                       dot_count++; 
                   }else
                   {
                       result = false;
                       break;
                   }

                }else if( isEe(*s) )
                {
                   if(e_count == 0)
                   {
                       e_count++;
                   }else
                   {
                       result = false;
                       break;
                   }
                   sign = INT_MAX;
                   dot_count = 0;
                }else
                {
                    if( !isDigit(*s) )
                    {
                        result = false;
                        break; 
                    }else
                    {
                        if(e_count == 0)
                        {
                            e_count_h = 1;
                        }else
                        {
                            e_count_e = 1;
                        }

                        if(dot_count == 0)
                        {
                            d_count_h = 1;
                        }else
                        {
                            d_count_e = 1;
                        }
                    }
                }
            }

            s++;

        }
    }
    
    if( e_count == 1 && (e_count_h == INT_MAX || e_count_e == INT_MAX) )
    {
        result = false;
    }
    
    if( dot_count == 1 && (d_count_h == INT_MAX && d_count_e == INT_MAX) )
    {
        result = false;
    }
    
    return result;
}