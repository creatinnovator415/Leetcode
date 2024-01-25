int numTrees(int n) {
    int depth;
    int index;
    int* dp;
    
    dp = (int*)malloc(sizeof(int) * (n+1));
    memset(dp, 0x0, sizeof(int) * (n+1));
    dp[0] = 1;
    dp[1] = 1;
    
    for(depth = 2; depth<=n; depth++)
    {
        for(index = 0; index < depth; index++)
        {
            dp[depth] += dp[index] * dp[depth - index - 1];
        }
    }
    
    return  dp[n];
}