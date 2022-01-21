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
    
    ListNode* middle(ListNode* head){
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        //phla middle nikalne ke liye fast->next phle ni null dekh lo.
        while(fast->next != NULL and fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode* merge2LL(ListNode* list1 ,ListNode* list2){
        ListNode *dummy = new ListNode(-1);
        ListNode *head = dummy , *tail = dummy;
        
        while(list1 != NULL && list2 != NULL){
            
            if(list1->val < list2->val){
                tail->next = list1;
                list1 = list1->next;
            }
            else{
                tail->next = list2;
                list2 = list2->next;
            }
            
            tail = tail->next;
        }
        
        //when one of the linked list get empty
        if(list2 == NULL){
            tail->next = list1;
        }
        else{
            tail->next = list2;
        }
        
        return dummy->next;    
    }
    
    ListNode* sortList(ListNode* head) {
        
        if(head == NULL or head->next == NULL)return head;
        
        ListNode* mid = middle(head);
        ListNode* midNext = mid->next;
        mid->next = NULL;
        
        ListNode* left = sortList(head);
        ListNode* right = sortList(midNext);
        
        return merge2LL(left,right);
    }
};
