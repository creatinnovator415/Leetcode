/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {

    struct ListNode* cur;
    struct ListNode* tmp;
    struct ListNode* prev;
    struct ListNode* left_node;
    struct ListNode* right_node;

    int count;
    
    count = 0;
    cur = NULL;
    left_node = NULL;
    right_node = NULL; 
    tmp = NULL;
    prev = NULL;
    
    while( count < left )
    {
        if(cur)
        {
            prev = cur;
            cur = cur->next;
        }else
        {
            prev = NULL;
            cur = head;
        }
        count++;
    }
    
    right_node = cur;
    left_node = prev;
    while( count <= right )
    {
        tmp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = tmp;
        count++;
    }
    
    right_node->next = cur;
    
    if(left_node == NULL)
    {
        head = prev;
    }else
    {
        left_node->next = prev;
    }
    
    
    
    return head;
}