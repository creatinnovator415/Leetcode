/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* record_node;
    struct ListNode* prev_node;
    struct ListNode* tmp_node;
    
    
    tmp_node = head;
    prev_node = NULL;
    record_node = NULL;
    
    while(tmp_node)
    {
        if( prev_node != NULL &&
            prev_node->val != tmp_node->val
          )
        {

            record_node->next = tmp_node;

        }
        
       if( (record_node == NULL) ||
           (record_node->val != tmp_node->val)
          )
        {
            record_node = tmp_node;
        }
        
        
        prev_node = tmp_node;
        tmp_node = tmp_node->next;
    }
    
    if(record_node)
    {
       record_node->next = NULL; 
    }
    

    
    
    return head;
}