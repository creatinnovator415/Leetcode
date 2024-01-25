int reverse(int x){
    int sign;
    int64_t digit;
    int64_t reverse;
    int count;
    int64_t num;
    
    
    sign = (x > 0) ? 1 : -1;
    reverse = 0;
    count = 0;
    num = llabs(x);
    
    while(num != 0)
    {
        digit = num%10;
        num/=10;
        reverse = reverse * 10 + digit; 
        printf("%d, %d, %d\n", num, digit, reverse);
    }

    if(sign == -1)
    {
        if(sign*reverse < INT_MIN)
        {
            return 0;
        }
    }else
    {
        if(sign*reverse > INT_MAX)
        {
            return 0;
        }
    }
    return sign*reverse;
}