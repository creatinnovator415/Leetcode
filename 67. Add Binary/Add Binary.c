char * addBinary(char * a, char * b){
    int a_len;
    int b_len;
    int bit_result;
    int max_len;
    int index;
    int overflow;
    char* result;
    
    a_len = strlen(a);
    b_len = strlen(b);
    max_len = a_len > b_len ? a_len : b_len;
    index = 0;
    overflow = 0;
    result = (char*)malloc(sizeof(char)*max_len+1+1);
    result[max_len+1] = '\0';
    
    while( index < (max_len+1) )
    {
        if(index < a_len && index < b_len)
        {
            bit_result = overflow + (a[a_len-index-1] - '0') + (b[b_len-index-1]- '0');
        }else if(index < a_len)
        {
            bit_result = overflow + (a[a_len-index-1] - '0');
        }else if(index < b_len) 
        {
            bit_result = overflow + (b[b_len-index-1] - '0');
        }else
        {
            bit_result = overflow;
        }
        
        overflow = (bit_result > 1) ? 1:0;
        result[max_len - index] = (bit_result & 1) + '0';
        index++;
    }
    
    return (result[0] == '0') ? &result[1] : &result[0];
}