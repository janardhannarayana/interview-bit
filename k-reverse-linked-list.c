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
listnode *reverse(listnode *start, listnode *curr, listnode *end);
listnode* reverseList(listnode* A, int B) {
    listnode *start = NULL;
    listnode *end = A;
    listnode *temp = A;
    listnode *root = NULL;
    listnode *curr = A;
    listnode *prev = NULL;

    
    int i = B;
    
    if (i <= 1 && i >= 0)
        return A;
    /*
    while(temp) {
        if (i == 0) {
            curr = temp;
            i++;
            temp = temp->next;
        } else if(i == B - 1) {
            p_start = temp;
            temp = temp->next;
            i++;
        } else if (i == B) {
            end = temp;
            i = 1;
            if (root == NULL) 
                root = reverse(start, curr, end);
            else 
                reverse(start, curr, end);
            curr = end;
            temp = temp->next;
            start = p_start;
        } else {
            temp = temp->next;
            i++;
        }
    }
    
    if (i > 0) {
        reverse(start, curr, NULL);
    }
    */
    
    
    while (curr) {
        end = curr;
        while(i && end) {
            end = end->next;
            i--;
            if (i == (B - 1))
                prev = end;
        }
        if (i > 0)
            end = NULL;
        i = B;
        if (root == NULL) 
            root = reverse(start, curr, end);
        else 
            reverse(start, curr, end);
        curr = end;
        start = prev;
    }
    
    return root;
        
    
}

listnode *reverse(listnode *start, listnode *curr, listnode *end)
{
    listnode *prev = end;
    listnode *next = NULL;
    
  
    
    while (curr != end && curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    if (start) {
        start->next = prev;
        
        return start;
    } else {
        return prev;   
    }
}

