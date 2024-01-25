
void _swapPairs(struct ListNode **result,struct ListNode **first,struct ListNode **second)
{
    struct ListNode * tmp;
    
    if(*first && *second)
    {
        (*first)->next = (*second)->next;
        (*second)->next = *first;
        tmp = *first;
        *first = *second;
        *second = tmp;
    }
    
    if(*result == NULL)
    {
        *result = *first;
    }else
    {
        (*result)->next = *first;
    }
}



struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode* first;
    struct ListNode* second;
    struct ListNode* result;
    struct ListNode* prev;
    int index;
    
    
    first = NULL;
    second = NULL;
    result = NULL;
    
    while(true)
    {
        if( (NULL == first) && (NULL == second) )
        {
            first = head;
            if(first)
            {
                second = first->next;
            }
            prev = NULL;
        }else
        {
            index = 0;
            
            while( (index < 2) && (first && second) )
            {
                 prev = first;
                 first = first->next;
                 second = second->next;
                 index++;
            }

        }
        
        _swapPairs((prev == NULL) ? &result : &prev, &first, & second);
        
        if(second == NULL)
        {
            break;
        }
    }
    
    return result;
}