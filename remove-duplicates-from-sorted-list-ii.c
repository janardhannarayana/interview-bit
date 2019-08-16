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
    listnode *prev = NULL;
    listnode *next = NULL;
    listnode *curr = NULL;
    listnode *c = NULL;
    listnode *n = NULL;
    
    if (A == NULL)
        return NULL;
        
    if (A->next == NULL)
        return A;
    
    curr = A;
    next = A->next;
    prev = NULL;
    while (next != NULL) {
        if (curr->val != next->val) {
            prev = curr;
            curr = next;
            next = next->next;
        } else {
            while(next != NULL && curr->val == next->val) {
                curr->next = next->next;
                next->next = NULL;
                free(next);
                next = curr->next;
            }
            if (prev == NULL) {
                curr->next = NULL;
                free(curr);
                curr = next;
                if (curr != NULL)
                    next = curr->next;
                A = curr;
            } else {
                prev->next = next;
                curr->next = NULL;
                free(curr);
                curr = prev;
            }
        }
    }
    return A;
}

