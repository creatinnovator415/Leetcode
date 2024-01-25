int lengthOfLastWord(char* s) {
    int str_len;
    int end_pos;
    int start_pos;
    
    str_len = strlen(s);
    end_pos = INT_MIN;
    start_pos = INT_MIN;
    str_len--;
    while(str_len>=0)
    {
        if( (str_len == 0) && (start_pos == INT_MIN) && (end_pos == INT_MIN) )
        {
            start_pos = str_len;
            end_pos = str_len;
            break;
        }else
        if( (s[str_len] != ' ') && (end_pos == INT_MIN) )
        {
            end_pos = str_len;
        }else if( (end_pos != INT_MIN)  && 
                  (s[str_len] == ' ') && 
                  (start_pos == INT_MIN)
                )
        {
            start_pos = str_len+1;
            break;
        }else if( (str_len == 0) && (start_pos == INT_MIN) )
        {
            start_pos = str_len;
            break;
        }
        
        str_len--;
    }
    return (end_pos == INT_MIN) ? 0 : (end_pos - start_pos) + 1;
}