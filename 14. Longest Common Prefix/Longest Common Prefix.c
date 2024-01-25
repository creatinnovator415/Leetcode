char * longestCommonPrefix(char ** strs, int strsSize){
    int str_index;
    int cmp_index;
    int match_count;
    cmp_index = 0;
    
    if(strsSize == 1)
    {
        return strs[0];
    }
    else    
    {
        while(true)
        {
            match_count = 1;

            for(str_index = 1; str_index < strsSize; str_index++)
            {
                if(strs[0][cmp_index] == strs[str_index][cmp_index])
                {
                    match_count++;
                }else
                {
                    break;
                }
            }

            if( (match_count != strsSize) || (strs[0][cmp_index] == '\0') )
            {
                break;
            }else
            {
                cmp_index++;
            }
        }
    }
    strs[0][cmp_index] = '\0';
    
    return strs[0];

}