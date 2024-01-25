#define ALLOC_LENGTH            (100)

char * intToRoman(int num){
    char* r_mark[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int  r_num[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char* result;
    char* mark;
    int result_index;
    int r_index;
    int alloc_length;
    
    
    alloc_length = ALLOC_LENGTH;
    result = (char*)malloc(sizeof(char)*alloc_length);
    result_index = 0;
    
    while(num > 0)
    {
        for(r_index = 0; r_index < sizeof(r_num)/sizeof(int); r_index++)
        {
            if(num >= r_num[r_index])
            {
                num -= r_num[r_index];
                break;
            }
        }

        mark = r_mark[r_index];
        
        while( *mark != '\0' )
        {
            result[result_index] = *mark;
            result_index++;   
            mark++;
            if( (result_index % ALLOC_LENGTH) == 0 )
            {
                alloc_length += ALLOC_LENGTH;
                result = (char*)realloc(result, sizeof(char)*alloc_length);
            }
        }
    }
    
    result[result_index] = '\0';
    
    return result;
}