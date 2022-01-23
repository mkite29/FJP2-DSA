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
    ListNode* partition(ListNode* head, int x) {
        ListNode *rDummy = new ListNode(-1) , *lDummy = new ListNode(-1);
        ListNode *rTail = rDummy , *lTail = lDummy;
        
        while(head != NULL){
            
            if(head->val < x){
                lTail->next = head;
                lTail = head;
            }else{
                rTail->next = head;
                rTail = head;
            }
            
            head = head->next;
        }
        
        lTail->next = rDummy->next;
        rTail->next = NULL;
        
        return lDummy->next;
    }
};
