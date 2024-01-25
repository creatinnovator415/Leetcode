/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    int count;
    struct ListNode* slow;
    struct ListNode* fast;
    struct ListNode* prev;
    
    if(NULL == head || NULL == head->next )
    {
        return head;
    }
    
    count = 1;
    prev = NULL;
    slow = head;
    fast = head->next;

    while( fast && fast->next )
    {
        prev = fast;
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow) 
        {
            break;
        }
        count+=2;
    }
    
    if(fast == NULL)
    {
        if(prev)
        {
            prev->next->next = head;  
        }
        
    }else
    {
        fast->next = head;
        count++;
    }
    
    count = ( count - (k%count) );
    slow = head;
    prev = NULL;
    
    while(count--)
    {
        prev = slow;
        slow = slow->next;
    }
    
    prev->next = NULL;
    head = slow;
    
    return head;
}