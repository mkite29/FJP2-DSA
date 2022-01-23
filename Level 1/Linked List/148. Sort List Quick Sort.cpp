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
    ListNode* partition(ListNode*head,int x){
        ListNode *lhead = new ListNode(-1);
        ListNode *ltail = lhead;
        
        ListNode *rhead = new ListNode(-1);
        ListNode *rtail = rhead;
        
        
        while(head != NULL){
            
            if(head->val < x){
                ltail->next = head;
                ltail = head;
            }else{
                rtail->next = head;
                rtail = head;
            }
            head = head->next;
            
        }
        
        ltail->next = NULL;
        rtail->next = NULL;
        return lhead->next;
        
    }
    
    ListNode* getTail(ListNode *Curr){
        if(Curr == NULL)return NULL;
        
        while(Curr->next != NULL)Curr = Curr->next;
        return Curr;
    }
    
    void randomize(ListNode *head){
        int size = 0;
        ListNode* curr = head;
        
        while(curr != NULL){
            size++;
            curr = curr->next;
        }
        
        int randomIdx = rand() % size  + 0;
        
        
        curr = head;
        while(randomIdx--){
            curr = curr->next;
        }
        
        int temp = head->val;
        head->val = curr->val;
        curr->val = temp;
        
    }
    
    ListNode* sortList(ListNode* head) {
        
        if(head == NULL or head->next == NULL)return head;
        
        randomize(head);
        ListNode *left = sortList(partition(head,head->val));
        ListNode *right = sortList(head->next);
        head->next = right;
        
        if(left == NULL)
            return head;
       
            ListNode *leftTail = getTail(left);
            leftTail->next = head;
            return left;
           
    }
};
