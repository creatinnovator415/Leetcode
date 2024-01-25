/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){

    struct ListNode* tmp_list1;
    struct ListNode* result_list;
    struct ListNode* tmp_list2;
    struct ListNode* result;
    
    tmp_list1 = list1;
    tmp_list2 = list2;
    result = NULL;

    
    while( (tmp_list1 != NULL) || (tmp_list2 != NULL) )
    {       
        if( (tmp_list2 == NULL) || 
            ( (tmp_list1 != NULL) && (tmp_list1->val <= tmp_list2->val) )
          )
        {
            if(result)
            {
                result_list->next = tmp_list1;
                result_list = tmp_list1;
            }else
            {
                result_list = tmp_list1;
                result = tmp_list1;
            }
         
            tmp_list1 = tmp_list1->next;
            
            if(tmp_list2 == NULL)
            {
              break; 
            }
        }else
        {
            if(result)
            {
                result_list->next = tmp_list2;
                result_list = tmp_list2;
            }else
            {
                result_list = tmp_list2;
                result = tmp_list2;
            }
            
            tmp_list2 = tmp_list2->next;
            
            if(tmp_list1 == NULL)
            {
              break; 
            }
        }
        
        
    }
    
    
    return result;
}