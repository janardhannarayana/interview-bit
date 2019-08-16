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
 * @Output Integer
 */
 
listnode *reverse_node(listnode *head);
int lPalin(listnode* A) {
    listnode *temp = A;
       if (A == NULL) {
            return 0;
       }
       if (A->next == NULL) {
            return 1;
       }
       listnode *middle = NULL;
       listnode *sp = A;
       listnode *fp = A;
       listnode *prev = NULL;
       
       while(fp && fp->next) {
            prev = sp;
            sp = sp->next;
            fp = fp->next->next;
       }
       prev->next = reverse_node(sp);
       listnode *middle_temp = prev->next;
       temp = A;
       middle = prev->next;
       while(temp != middle) {
            if (temp->val == middle_temp->val) {
                temp = temp->next;
                middle_temp = middle_temp->next;
                continue;
            } else {
                return 0;
            }
       }
       
       return 1;
       
}

listnode *reverse_node(listnode *head) {
    listnode *curr = NULL;
    listnode *next = NULL;
    listnode *prev = NULL;
    
    curr = head;
    next = head;
    
    while(curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

