char * convert(char * s, int numRows){

    char* result;
    int row_index;
    int str_length;
    int loc;
    int diff;
    int loop;
    int result_index;
    int section;
    int inner_count;
    int inner_limit;
    
    str_length = strlen(s);
    
    result = malloc(str_length*sizeof(char) + 1);

    section = ( (numRows*2) > 2 ) ? ( (numRows*2) - 2 ) : 1;
    result_index = 0;
    
    for(row_index = 0; row_index < numRows; row_index++)
    {
        diff = numRows*2 - (row_index+1) * 2;
        loc = row_index;
        loop = 1;
        inner_count = 0;
        inner_limit = ((0 == row_index) || ((numRows - 1) == row_index)) ? 1:2;
        
        while(loc < str_length) 
        {
            result[result_index] = s[loc];
            result_index++;
            inner_count++;
            
            if(inner_count >= inner_limit)
            {
               loc = loop * section + row_index;
               loop++;
               inner_count = 0;
            }else
            {
                loc += diff;
            }
            
        };
    }

    result[str_length] = '\0';
    return result;
}
