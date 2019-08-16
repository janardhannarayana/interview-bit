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
listnode *reverse(listnode *head);
listnode* reorderList(listnode* A) {
    listnode *middle = NULL;
    listnode *sp = A;
    listnode *fp = A;
    int flag = 1;
    int len = 0;
    
    while (fp && fp->next) {
        sp = sp->next;
        fp = fp->next->next;
        len++;
    }
    
    if (fp)
        len = (len*2) + 1;
    else
        len = len * 2;
        
    middle = sp;
    
    listnode *list1 = NULL;
    listnode *list2 = NULL;
    
    list1 = A;
    list2 = middle->next;
    middle->next = NULL;
    
    list2 = reverse(list2);
    sp = list1;
    fp = sp;
    list1 = list1->next;
    
    while(list1 && list2) {
        if (flag) {
            sp->next = list2;
            list2 = list2->next;
            sp = sp->next;
            flag = 0;
        } else {
            sp->next = list1;
            list2 = list2->next;
            sp = sp->next;
            flag = 1;
        }
    }
    
    while (list1) {
        sp->next = list1;
        sp = sp->next;
        list1 = list1->next;
    }
    while (list2) {
        sp->next = list2;
        sp = sp->next;
        list2 = list2->next;
    }
    return fp;
}

listnode *reverse(listnode *head)
{
    listnode *next = head;
    listnode *prev = NULL;
    listnode *curr = head;
    
    while(curr) {
        next = next->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        
    }
    return prev;
}
