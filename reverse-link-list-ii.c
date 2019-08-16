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
 * @input C : Integer
 * 
 * @Output head pointer of list.
 */
 void reverse_node(listnode **start, listnode **end) {
     if (*start == NULL || *end == NULL) {
        return;
     }
     
     if ((*start)->next == NULL)
        return;
     
     listnode *curr = (*start);
     listnode *prev = NULL;
     listnode *next = (*start)->next;
     
     while (curr) {
         if (prev == NULL) {
             next = curr->next;
             curr->next = (*end)->next;
             (*end)->next = NULL;
            *end = curr;
         } else {
             next = curr->next;
             curr->next = prev;
         }
         prev = curr;
         curr = next;
         
     }
     *start = prev;
 }
listnode* reverseBetween(listnode* A, int B, int C) {

    listnode *temp = NULL;
    listnode *start = NULL;
    listnode *end = NULL;
    temp = A;
    int i = 1; 
   
    if (A == NULL)
        return NULL;
    if (A->next == NULL)
        return A;
    while (temp) {
        if (i == B) {
            start = temp;
        }
        if (i == C) {
            end = temp;
        }
        i++;
        temp = temp->next;
    }

    reverse_node(&start, &end);
    temp = A;
    i = 1;
    if (B == 1) {
        A = start;
        return A;
    }

    while(B - 1 != i) {
        i++;
        temp = temp->next;
    }
    
    temp->next = start;
    return A;
}

