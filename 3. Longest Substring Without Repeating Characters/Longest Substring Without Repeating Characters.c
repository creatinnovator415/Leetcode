#define TOTAL_ALPHABETS     (128)

int lengthOfLongestSubstring(char * s){
    int s_index;
    int e_index;
    int index;
    int max_length;
    int* count;
    int a_index;
    int str_len;
 
    count = (int*)malloc(sizeof(int)*TOTAL_ALPHABETS);
    str_len = strlen(s);
    
    for(s_index = 0; s_index<TOTAL_ALPHABETS; s_index++)
    {
        count[s_index] = -1;
    }
    
    index = 0;
    s_index = 0;
    max_length = 0;
    
    for(index = 0; index < str_len; index++)
    {
        if(count[s[index]] >= s_index)
        {
            s_index = count[s[index]] + 1;
            count[s[index]] = index;
        }else
        {
            count[s[index]] = index;
            if( (index - s_index + 1) > max_length)
            {
                max_length = index - s_index + 1;
            }
        }
    }
    
    return max_length;
    
}