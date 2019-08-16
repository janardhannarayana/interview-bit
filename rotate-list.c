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
listnode* rotateRight(listnode* A, int B) {
    listnode *curr = NULL;
    listnode *next = NULL;
    listnode *root = A;
    listnode *end = NULL;
    int len = 0;
    curr = A;
    
    if (A == NULL)
        return NULL;
        
    if (A->next == NULL)
        return A;
    while (curr != NULL) {
        curr = curr->next;
        len++;
    }
    int i = len-(B%len);
    curr = A;
    end = A;
    next = A->next;
    if (i == 0)
        return A;
    while (i - 1) {
        curr = next;
        next = next->next;
        end = end->next;
        i--;
    }
    
    while(end->next != NULL) {
        end = end->next;
    }
    
    curr->next = NULL;
    end->next = root;
    root = next;
    
    return root;
}

