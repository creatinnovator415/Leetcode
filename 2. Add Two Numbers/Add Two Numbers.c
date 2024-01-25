/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* result_head;
    struct ListNode* result_node;
    struct ListNode* l1_node;
    struct ListNode* l2_node;
    int sum;
    int overflow;
    
    overflow = 0;
    l1_node = l1;
    l2_node = l2;
    result_head = malloc(sizeof(struct ListNode));
    result_head->next = NULL;
    result_head->val = 0;
    result_node = result_head;
    
    while( (l1_node != NULL) || (l2_node != NULL) || overflow)
    {   
        sum = 0;
        
        if(l1_node)
        {
            sum += l1_node->val;
        }
        
        if(l2_node)
        {
            sum += l2_node->val;
        }

        sum += overflow;
        overflow = sum/10;
        result_node->val = sum % 10;
        
        if(l1_node)
        {
            l1_node = l1_node->next;
        }
        
        if(l2_node)
        {
            l2_node = l2_node->next;
        }

        if(l1_node || l2_node || overflow)
        {
           result_node->next = malloc(sizeof(struct ListNode));
           result_node = result_node->next;  
           result_node->next = NULL;
           result_node->val = 0;
        }
       
    }
    
    return result_head;
}