 ListNode *reverse(ListNode *head){
        
     if(head == NULL || head->next == NULL)return head;
    
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

void unfold(ListNode *head)
{
    ListNode *dummy1 = new ListNode(-1);
    ListNode *tail1 = dummy1;
    
    ListNode *dummy2 = new ListNode(-1);
    ListNode *tail2 = dummy2;
    
    while(head != NULL){
        tail1->next = head;
        tail1 = head;
        head = head->next;
        
        if(head != NULL){
            tail2->next = head;
            tail2 = head;
            head = head->next;
        }
    }
    
    tail1->next = NULL;
    tail2->next = NULL;
    
    tail1->next = reverse(dummy2->next);
    
    //yaha head update kerne se change nahi ayega bcz head variable yaha 
    //new decalre mana jayega and ager next mei yani pointer mei change 
    //late hai to vo persist karega.
    
    //head = dummy1->next;
   
  
}
