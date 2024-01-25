/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void swap(struct TreeNode* a, struct TreeNode* b)
{
    int tmp;
    
    tmp = a->val;
    a->val = b->val;
    b->val = tmp;
}

void recoverTree(struct TreeNode* root) {
    struct TreeNode* current;
    struct TreeNode* prev;
    struct TreeNode* tmp;
    struct TreeNode* first;
    struct TreeNode* second;
    
    current = root;
    prev = NULL;
    first = NULL;
    second = NULL;
    
    while(current != NULL)
    {
        if( prev && prev->val > current->val)
        {  
            if(first == NULL)
            {
                first = prev;
            }
            
            second = current;
            
        }
        
        if(current->left == NULL)
        {
            prev = current;
            current = current->right;
        }else
        {
            tmp = current->left;
            
            while(tmp->right != NULL && tmp->right != current)
            {
                tmp = tmp->right;
            }

            if(tmp->right == NULL)
            {
                tmp->right = current;
                current = current->left;
                continue;
            }else
            {
               tmp->right = NULL;
               prev = current;
               current = current->right;
            }
            
        }
        
        
        
        
    }
    
    if(first && second)
    {
        swap(first, second);
    }
    

}