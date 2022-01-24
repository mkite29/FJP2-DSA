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
    ListNode* deleteDuplicates(ListNode* h) {
        
        if(h == NULL || h->next == NULL)return h;
        
        ListNode *dummy = new ListNode(-101);
        ListNode *tail = dummy;
        
        while(h != NULL){
            
            if(h->val != tail->val){
                tail->next = h;
                tail = tail->next;
            }
            h = h->next;
        }
        
        tail->next = NULL;
        
        return dummy->next;
    }
};
