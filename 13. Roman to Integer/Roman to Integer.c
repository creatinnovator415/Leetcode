int romanToInt(char * s){
    char* r_mark[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int  r_num[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    int r_index;
    int result;
    char* mark;
    char* tmp;
    bool valid;
    
    result = 0;
    
    while(*s != '\0')
    {
        for(r_index = 0; r_index < sizeof(r_mark)/sizeof(int); r_index++)
        {
            mark = r_mark[r_index];
            tmp = s;
            valid = true;
            
            while( *mark != '\0' )
            {
                if(*mark != *tmp)
                {
                    valid = false;
                    break;
                }
                mark++;
                tmp++;
            }
           
            if(valid)
            {
                s = tmp;
                result += r_num[r_index];
                break;
            }
        }
    }
    
    return result;
    
    
}