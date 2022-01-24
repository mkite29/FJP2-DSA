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
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode *dummy = new ListNode(-1);
        ListNode *tail = dummy;
        
        
        while(head != NULL){
            
            if(head->next == NULL or head->next->val != head->val){
                tail->next = head;
                tail = head;
                head = head->next;
            }
            else{
                ListNode *Curr = head;
                while(Curr!=NULL and Curr->val == head->val){
                    Curr = Curr->next;
                }
                
                head = Curr;
            }
        }
        
        tail->next = NULL;
        return dummy->next;
    }
};
