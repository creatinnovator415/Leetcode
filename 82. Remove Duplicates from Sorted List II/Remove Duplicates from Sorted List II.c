/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* tmp;
    struct ListNode* prev;
    struct ListNode* prev_next;
    
    tmp = head;
    prev = NULL;
    
    while(tmp)
    {
       
        if( ( tmp->next == NULL ) || 
            ( tmp->val != tmp->next->val )
          )
        {
            prev_next = tmp;
            if(prev != NULL)
            {
                if( (prev->next != tmp) &&
                    (prev->next->val == tmp->val)
                  )
                {
                    prev->next = tmp->next;
                    prev_next = prev;
                }
            }
            
            if( (head != tmp) &&
                (head->val == tmp->val)
              )
            {
               head = tmp->next;
            }

            

            prev = prev_next;
        }
        
        
        tmp = tmp->next;
    }
    
    return head;
}