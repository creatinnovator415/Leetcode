bool isMatch(char* s, char* p) {
    bool** dp;
    int s_len;
    int p_len;
    int s_index;
    int p_index;
    
    s_len = strlen(s);
    p_len = strlen(p);
    
    dp = (bool**)malloc(sizeof(bool*)*(s_len+1));
    memset(dp, 0x0, sizeof(bool*)*(s_len+1));
    dp[0] = (bool*)malloc(sizeof(bool)*(s_len+1)*(p_len+1));
    
    dp[0][0] = true;
    
    for(s_index = 1; s_index <= s_len; s_index++)
    {
        if(dp[s_index] == NULL)
        {
            dp[s_index] = dp[0] + s_index*(p_len+1);
        }
        
        dp[s_index][0] = false;
    }

    for(p_index = 1; p_index <= p_len; p_index++)
    {
        if(dp[0][p_index-1] && p[p_index-1] == '*')
        {
            dp[0][p_index] = true;
        }else 
        {
            dp[0][p_index] = false;
        }
        
    }
    
    
    for(s_index = 1; s_index <= s_len; s_index++)
    {
        for(p_index = 1; p_index <= p_len; p_index++)
        {
            
            if(p[p_index-1] == '*')
            {
                dp[s_index][p_index] = dp[s_index-1][p_index] || dp[s_index][p_index-1];
            }else if(p[p_index-1] == '?')
            {
                dp[s_index][p_index] = dp[s_index-1][p_index-1];
            }else
            {
                dp[s_index][p_index] = dp[s_index-1][p_index-1] && (s[s_index-1] == p[p_index-1]);
            }
        }
    }
    
    return dp[s_len][p_len];
}