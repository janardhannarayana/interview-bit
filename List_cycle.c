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
listnode* detectCycle(listnode* A) {
    listnode *sp = A;
    listnode *fp = A;
    
    while(sp && fp && fp->next) {
        sp = sp->next;
        fp = fp->next->next;
        
        if (sp == fp) {
            sp = A;
            if (sp == fp) {
                return sp;
            }
            while(sp->next != fp->next) {
                sp = sp->next;
                fp = fp->next;
            }
            return sp->next;
        }
    }
    return NULL;
}

