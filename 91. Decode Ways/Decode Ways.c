int numDecodings(char* s) {
    int* dp;
    int str_len;
    int index;

    
    str_len = strlen(s);
    dp = (int*)malloc(sizeof(int)* (str_len+1));

    dp[0] = 1;
 
    
    for(index = 1 ; index < str_len+1; index++)
    {

        dp[index] = (s[index - 1] == '0') ? 0 : dp[index - 1];
        
        if ( (index > 1) && 
             ( (s[index - 2] == '1') || 
               (s[index - 2] == '2' && s[index - 1] <= '6')
             )
             
           )
        {
                dp[index] += dp[index - 2];
        }
    }
    
    
    return dp[str_len];
}