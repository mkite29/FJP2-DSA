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
    ListNode *middleNode(ListNode *head) {
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        //akhiri mid dega pehla mid nahi dega
        while(fast!=NULL && fast->next !=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        
        return slow;
    }
    
    ListNode *reverse(ListNode *head){
        
     if(head == NULL || head->next==NULL)return head;
    
    ListNode *prev = NULL;
    ListNode *curr = head;
    
    while(curr != NULL){
        
        ListNode *lead = curr->next;
        curr->next = prev;
        prev = curr;
        curr = lead;
    }
    return prev;
    }
    
    void reorderList(ListNode* head) {
        
        ListNode *mid = middleNode(head);
        ListNode *second = reverse(mid->next);
        
        mid->next = NULL;
        
        ListNode *dummy = new ListNode(-1);
        ListNode *tail = dummy;
        
        while(head != NULL or second != NULL){
            if(head != NULL){
                tail->next = head;
                tail = head;
                head = head->next;
            }
            
            if(second != NULL){
                tail->next = second;
                tail = second;
                second = second->next;
            }
        }
        
        tail->next = NULL;
        head = dummy->next;
    }
};
