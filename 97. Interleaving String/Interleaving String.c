

bool isInterleave(char* s1, char* s2, char* s3) {
    int** dp;
    int s1_index;
    int s2_index;
    int s1_len;
    int s2_len;
    int s3_len;

    s3_len = strlen(s3);
    s1_len = strlen(s1);
    s2_len = strlen(s2);
    

    if( (s1_len+s2_len) != s3_len)
    {
        return false;
    }
    
    dp = (int**) malloc(sizeof(int*)*(s1_len+1));
    memset(dp, 0x0, sizeof(int*)*(s1_len+1));
    dp[0] = (int*) malloc(sizeof(int)*(s1_len+1)*(s2_len+1));
    memset(dp[0], 0x0, sizeof(int)*(s1_len+1)*(s2_len+1));

    for(s1_index = 0; s1_index <= s1_len; s1_index++)
    {
        for(s2_index = 0; s2_index <= s2_len; s2_index++)
        {
            if(NULL == dp[s1_index])
            {
                dp[s1_index] = dp[0] + s1_index*(s2_len+1);
            }

            if(0 == s2_index && 0 == s1_index)
            {
                dp[s1_index][s2_index] = 1;
            
            }else if(0 == s1_index)
            {
                if( dp[s1_index][s2_index-1] && 
                    s3[s1_index+s2_index-1] == s2[s2_index-1]
                )
                {
                    dp[s1_index][s2_index] = 1;
                }
            }else if(0 == s2_index) 
            {
                if( dp[s1_index-1][s2_index] && 
                      s3[s1_index+s2_index-1] == s1[s1_index-1]
                    )
                {
                   dp[s1_index][s2_index] = 1; 
                }

            }else
            {
                dp[s1_index][s2_index] = ( dp[s1_index][s2_index-1] && s3[s1_index+s2_index-1] == s2[s2_index-1] ) || 
                                         ( dp[s1_index-1][s2_index] && s3[s1_index+s2_index-1] == s1[s1_index-1] );
            }
        }  
    }
    
    return dp[s1_len][s2_len];
}