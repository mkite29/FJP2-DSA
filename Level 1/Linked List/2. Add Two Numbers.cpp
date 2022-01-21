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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* head =  dummy;
        ListNode* tail = dummy;
        
        int carry = 0;
        while(l1 != NULL or l2 != NULL or carry > 0){
            int d1 = (l1 == NULL)? 0 : l1->val;
            int d2 = (l2 == NULL)? 0 : l2->val;
            
            ListNode* temp = new ListNode((d1 + d2 + carry)%10);
            carry = (carry + d1 + d2)/10;
            
            tail->next = temp;
            tail = tail->next;
            
            if(l1 != NULL)l1 = l1->next;
            if(l2 != NULL)l2 = l2->next;
            
        }
        
        return dummy->next;
    }
};
