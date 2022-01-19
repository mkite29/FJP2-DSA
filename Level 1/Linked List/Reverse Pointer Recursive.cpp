/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    void reverseHP(ListNode *node , ListNode **newhead){
    
        if(node==NULL || node->next==NULL){
            *newhead = node;
            return;
        }
        reverseHP(node->next,newhead);
        node->next->next = node;
    }
    
    ListNode* reverseList(ListNode* head) {
        
        if(head == NULL)return NULL;
        
        ListNode *newhead = NULL;
        ListNode *Curr = head;
        reverseHP(Curr , &newhead);
        Curr->next = NULL;
        
        return newhead;
        
        
    }
};
