#define MAX_BITS        (31)


int divide(int dividend, int divisor)
{
    int64_t quotient;
    int index;
    int64_t dividend_tmp;
    int64_t divisor_tmp;
    int divisor_left;
    int sign;

    
    if( dividend > 0 )
    {
        sign = ( divisor < 0 ) ? -1 : 1; 
        
    }else
    {
        sign = ( divisor > 0 ) ? -1 : 1; 
    }
    
    dividend_tmp = dividend;
    divisor_tmp = divisor;
    dividend_tmp = llabs(dividend_tmp);
    divisor_tmp = llabs(divisor_tmp);
    divisor_left = 0;
    quotient = 0;
    
    for (index = MAX_BITS; index >= 0; index--)
    {
        if ( ((dividend_tmp >> index)) >= (divisor_tmp) )
        {

            dividend_tmp -= (divisor_tmp << index);
            quotient += (1LL << index);
            
        }
    }
    

    return ( (quotient *  (sign)) > INT_MAX ) ? INT_MAX : (quotient *  (sign));

}