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
    
    ListNode *reverse(ListNode *head){
        
        ListNode * prev = NULL;
        ListNode *curr = head;
        
        while(curr != NULL){
            ListNode *ahead = curr->next;
            curr->next = prev;
            prev = curr;
            curr = ahead;
        }
        
        return prev;
        
    }
    
    ListNode *middle(ListNode *head){
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    bool isPalindrome(ListNode* head) {
        
    if(head == NULL || head->next == NULL)return true;
        
    ListNode *mid = middle(head);
    ListNode *second = reverse(mid->next);
        
        while(head != NULL and second != NULL){
            
            if(head->val != second->val)
                return false;
            
            head = head->next;
            second = second->next;
        }
        
        return true;
    }
};
