/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode* tmp_head;
    struct ListNode* tmp_tail;
    struct ListNode* tmp;
    struct ListNode* prev;
    
    tmp = head;
    tmp_head = NULL;
    tmp_tail = NULL;
    prev = NULL;
    
    while(tmp)
    {
        if(tmp->val >= x)
        {
            if(tmp_head == NULL)
            {
                tmp_head = tmp;
                tmp_tail = tmp;
            }else
            {
                tmp_tail->next = tmp;
                tmp_tail = tmp;
            }
            
            if(prev == NULL)
            {
                if(tmp->next)
                {
                    head = tmp->next; 
                }else
                {
                    head = tmp_head;
                }
               
            }else
            {
                prev->next = tmp->next;
            }
            
            tmp = tmp->next ;
            tmp_tail->next = NULL;
        }else
        {
            prev = tmp;
            tmp = tmp->next ;
        }
        
        
        
    }
    
    if(prev)
    {
        prev->next = tmp_head;
  
    }
    
    return head;
}