#define TOTAL_ALPHABETICS         (128)


char* minWindow(char* s, char* t) {
    int s_len;
    int t_len;
    int index;
    int left;
    int count;
    int* map;
    char base;
    int min_len;
    int min_left;
    
    s_len = strlen(s);
    t_len = strlen(t);
    map = (int*)malloc(sizeof(int)*TOTAL_ALPHABETICS);
    memset(map, 0x0, sizeof(int)*TOTAL_ALPHABETICS);
    index = 0;

    min_len = INT_MAX;
    min_left = 0;
    
    while(index < t_len)
    {
        map[t[index] - 'A']++;
        index++;
    }

    index = 0;
    left = 0;
    count = 0;
    
    while(index < s_len)
    {
        map[s[index] - 'A']--;
        
        if(map[s[index] - 'A'] >= 0)
        {
            count++;
        }
        
        while(count == t_len)
        {
            if(min_len > index - left + 1)
            {
                min_len = index - left + 1;
                min_left = left;
            }
            
            map[s[left] - 'A']++;
            
            if(map[s[left] - 'A'] > 0)
            {
                count--;
            }

            left++;
            
        }
        
        index++;
    }
    
    

    min_len = (min_len == INT_MAX) ? 0 : min_len;
    
    s[min_left+min_len] = '\0';
    
    return &s[min_left];
}