/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define ALLOC_LENGHT                (100)
int* result;
int alloc_length;

void _inorderTraversal(struct TreeNode* root, int* returnSize) 
{
    if(NULL == root)
    {
        return;
    }
    
    _inorderTraversal(root->left, returnSize);
    result[*returnSize] = root->val;
    (*returnSize)++;
    if( 0 == ( alloc_length % ALLOC_LENGHT ) )
    {
        result = (int*)realloc(result, sizeof(int)*alloc_length);
    }
    _inorderTraversal(root->right, returnSize);
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    
    alloc_length = ALLOC_LENGHT;
    *returnSize = 0;
    result = (int*)malloc(sizeof(int)*alloc_length);
    _inorderTraversal(root, returnSize);
    return result;
}