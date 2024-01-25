#define MAX_LENGTH      (32)

bool isPalindrome(int x){
    char* s;
    int num;
    int s_index;
    int l_index;
    int r_index;
    
    s = (char*)malloc(sizeof(char) * MAX_LENGTH);
    num = x;
    s_index = 0;
    
    if( x >= 0 )
    {
        while(num)
        {
            s[s_index] = (num % 10) + '0';
            s_index++;
            num /= 10;
        }
    }else
    {
        return false;
    }
    
    l_index = 0;
    r_index = s_index - 1;
    
    while(l_index <= r_index)
    {
        if(s[l_index] != s[r_index])
        {
            return false;
        }
        l_index++;
        r_index--;
    }
    
    return true;
}