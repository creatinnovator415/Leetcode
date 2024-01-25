int climbStairs(int n) {
    int* dp;
    int index;
    if (n <= 1) return 1;

    dp = (int*)malloc(sizeof(int)*n);

    dp[0] = 1; 
    dp[1] = 2;

    for (index = 2; index < n; index++) 
    {
        dp[index] = dp[index - 1] + dp[index - 2];
    }
    
    return dp[n-1];
}