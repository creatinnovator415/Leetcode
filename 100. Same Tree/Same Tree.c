/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool _isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    bool result;
    
    result = false;
    
    if(p && q)
    {
        if(p->val == q->val)
        {
            if(_isSameTree(p->left, q->left) && _isSameTree(p->right, q->right))
            {
                result = true;
            }else
            {
                result = false;
            }
        }
    }else if( NULL == p && NULL == q)
    {
        result = true;
    }
    
    return result;
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    
    return _isSameTree(p, q);
}