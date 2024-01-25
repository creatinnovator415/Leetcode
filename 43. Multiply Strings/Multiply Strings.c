int charToNum(char* num)
{
    return num - '0';
}

char* multiply(char* num1, char* num2) {
    int num1_len;
    int num2_len;
    int num1_index;
    int num2_index;
    int num;
    char* result;
    int count;
    
    
    
    
    num1_len = strlen(num1);
    num2_len = strlen(num2);
    count = num1_len+num2_len+1;
    result = (char*)malloc(sizeof(char)*(count));
    memset(result, '0', sizeof(char)*(count));
    num = 0;
    result[count-1] = '\0';
    count--;
    
    
    if( ( (num1_len == 1) && (num1[0] == '0') )||( (num2_len == 1) && (num2[0] == '0') ) )
    {
        result[count-1] = '0';
        return  &result[count-1];
    }else
    {
        for(num1_index  = num1_len - 1; num1_index >= 0; num1_index--)
        {
             for(num2_index = num2_len - 1; num2_index >= 0; num2_index--)
             {
                 num = charToNum(num1[num1_index]) * charToNum(num2[num2_index]);
                 num = (charToNum(result[num1_index+num2_index+1]) + num);
                 result[num1_index+num2_index+1] = (num%10) + '0';
                 result[num1_index+num2_index] = charToNum(result[num1_index+num2_index]) + (num/10) + '0';
             }

        }

    }
    
    return (result[0] == '0') ? &result[1] : &result[0];                     
}