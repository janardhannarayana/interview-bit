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
 * @input B : Integer
 * 
 * @Output head pointer of list.
 */
listnode* removeNthFromEnd(listnode* A, int B) {
    
    listnode *sp = A;
    listnode *fp = A;
    int len = 0;
    
    if (A == NULL)
        return NULL;
        
    while (fp && fp->next) {
        len++;
        sp = sp->next;
        fp = fp->next->next;
    }
    
    if (fp == NULL)
        len = len * 2;
    else if (fp->next == NULL)
        len = (len*2) + 1;
    
    listnode *temp = A;
    listnode *prev = NULL;
    int i = len-B;
    
    if (i <= 0) {
        A = A->next;
        free(temp);
    } else {
        
        while (i) {
            prev = temp;
            temp = temp->next;
            i--;
        }
        prev->next = temp->next;
        temp->next = NULL;
        free(temp);
    }
    return A;
}
