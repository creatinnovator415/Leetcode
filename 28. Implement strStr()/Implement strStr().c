int strStr(char* haystack, char* needle) {
    int h_index;
    int n_index;
    int tmp_index;
    
    
    h_index = 0;
    
    while( haystack[h_index] != '\0' )
    {
        n_index = 0;
        tmp_index = h_index;
        
        while(true)
        {
            if(needle[n_index] == '\0')
            {
                return h_index;
            }else if(haystack[tmp_index] != needle[n_index])
            {
                break;
            }
            
            n_index++;
            tmp_index++;
        }
        h_index++;
    }
    
    return -1;
    
}