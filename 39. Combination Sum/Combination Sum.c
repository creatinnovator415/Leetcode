/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define ALLOC_LENGTH                (100)
#define MAX_STACK_LENGTH            (100)
int alloc_length = ALLOC_LENGTH;
int **result;
void _combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes, int* stack, int stack_ptr, int pos){
    int index;
    
    for(index = pos; index < candidatesSize; index++)
    {
        stack[stack_ptr+1] = candidates[index];
        if(target == candidates[index])
        {   
            //printf("stack_ptr:%d, *returnSize:%d\n", stack_ptr, *returnSize);
            stack_ptr++;
            result[*returnSize] = (int*)malloc(sizeof(int)*(stack_ptr+1));
            memcpy(result[*returnSize], stack, sizeof(int)*(stack_ptr+1));
            (*returnColumnSizes)[*returnSize] = stack_ptr+1;
            (*returnSize)++;
            if( (*returnSize % ALLOC_LENGTH) == 0 )
            {
                //printf("Realloc *returnSize:%d\n", *returnSize);
                alloc_length+=ALLOC_LENGTH;
                result = (int**)realloc(result, sizeof(int*)*alloc_length);
                *returnColumnSizes = (int*)realloc(*returnColumnSizes, sizeof(int)*alloc_length);
            }
            stack_ptr--;
        }else if(target > candidates[index])
        {
            //printf("target:%d, index:%d, stack_ptr:%d, can:%d\n", target, index, stack_ptr, candidates[index]);
            _combinationSum(candidates, candidatesSize, target - candidates[index], returnSize, returnColumnSizes, stack, stack_ptr+1, index);
        }
        
    }
    
    
    
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    int stack[MAX_STACK_LENGTH];
    int stack_ptr;


    *returnSize = 0;
    result = (int**)malloc(sizeof(int*)*alloc_length);
    *returnColumnSizes = (int*)malloc(sizeof(int)*alloc_length);
    stack_ptr = -1;
    _combinationSum(candidates, candidatesSize, target, returnSize, returnColumnSizes, stack, stack_ptr, 0);
    
    if (*returnSize == 0) 
    {
        free(result);
        free(*returnColumnSizes);
        *returnColumnSizes = NULL;
        result = NULL;
    }

    return result;
    
}