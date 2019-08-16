/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 * 
 * typedef struct ListNode listnode;
 * 
 * listnode* listnode_new(int val) {
 *     listnode* node = (listnode *) malloc(sizeof(listnode));
 *     node->val = val;
 *     node->next = NULL;
 *     return node;
 * }
 */
/**
 * @input A : Head pointer of linked list 
 * 
 * @Output head pointer of list.
 */
listnode* deleteDuplicates(listnode* A) {
    
    listnode *curr = A;
    listnode *next = A;
    
    if (!A) 
        return NULL;
        
    if (A->next == NULL)
        return A;
    
    next = curr->next;
    while(next != NULL) {
        if( curr->val != next->val) {
            curr = next;
            next = next->next;
        } else {
            curr->next = next->next;
            next->next = NULL;
            free(next);
            next = curr->next;
        }
    }
    return A;
}

