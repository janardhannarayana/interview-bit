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
 * @input B : Head pointer of linked list 
 * 
 * @Output head pointer of list.
 */
listnode* mergeTwoLists(listnode* A, listnode* B) {
    listnode *root = NULL;
    listnode *temp = NULL;
    listnode *curr_A = A;
    listnode *curr_B = B;
    
    
    while (curr_A != NULL && curr_B != NULL) {
        if (curr_A->val < curr_B->val) {
            if (root == NULL) {
                root = curr_A;
                curr_A = curr_A->next;
                root->next = NULL;
                temp = root;
            } else {
                temp->next = curr_A;
                curr_A = curr_A->next;
                temp = temp->next;
                temp->next = NULL;
            }
        } else {
            if (root == NULL) {
                root = curr_B;
                curr_B = curr_B->next;
                root->next = NULL;
                temp = root;
            } else {
                temp->next = curr_B;
                curr_B = curr_B->next;
                temp = temp->next;
                temp->next = NULL;
            }
        }
    }
    
    if (curr_A != NULL) {
        temp->next = curr_A;
    }
    
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    if (curr_B != NULL) {
        temp->next = curr_B;
    }
    
    while (temp->next != NULL) {
        temp = temp->next;
    }
    return root;
}
