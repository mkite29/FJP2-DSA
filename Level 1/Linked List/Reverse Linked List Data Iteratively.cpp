     node* getAt(int p) {
    int cnt = 0;
    node* temp = head;
    while (cnt < p) {
      cnt++;
      temp = temp->next;
    }
    return temp;
  }
void swap(node *n1 , node *n2){
        
        int temp = n1->val;
        n1->val = n2->val;
        n2->val = temp;
   }
   
void reverse_di() {
    //write your code here
    int left = 0;
    int right = size() - 1;
    
    while(left < right){
        node *n1 = getAt(left);
        node *n2 = getAt(right);
        
        swap(n1,n2);
        left++,right--;
    }
    
  }
