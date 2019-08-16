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
listnode* swapPairs(listnode* A) {
    listnode *curr = NULL;
    listnode *prev = NULL;
    listnode *next = NULL;
    
    if (A == NULL) 
        return NULL;
    if (A->next == NULL)
        return A;

    prev = NULL;
    curr = A;
    next = curr->next;
    
    while(curr && next) {
        
        curr->next = next->next;
        next->next = curr;
        if (prev == NULL) {
            A = next;
        } else {
            prev->next = next;
        }
        prev = curr;
        curr = curr->next;
        if (curr)
            next = curr->next;
        else
            next = NULL;
    }
    return A;
}

