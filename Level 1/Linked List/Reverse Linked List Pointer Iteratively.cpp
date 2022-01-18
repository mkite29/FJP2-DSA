  void reverse_pi() {
    
    if(head == NULL || head->next==NULL)return;
    
    node *prev = NULL;
    node *curr = head;
    
    while(curr != NULL){
        
        node *lead = curr->next;
        curr->next = prev;
        prev = curr;
        curr = lead;
    }
  
    head = prev;
    
  }
