class LRUCache {
     class Node{
        
       public:
         
        int key;
        int val;
        Node *prev;
        Node *next;
        
       
         
        Node (int key , int val){
            this->key = key;
            this->val = val;
        }
        
    };
    
    int size = 0 , capacity;
    Node *head , *tail;
    unordered_map<int,Node*> hm;
    
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        
        head ->next = tail;
        tail->prev = head;
        size = 0;
        
        
    }
    
    int get(int key) {
        
        if(!hm[key]){
            return -1;
        }
        
        Node *Curr = hm[key];
        
        //Remove At
        Curr->prev->next = Curr->next;
        Curr->next->prev = Curr->prev;
        
        //Add at
        Curr->prev = head;
        Curr->next = head->next;
        Curr->prev->next = Curr;
        Curr->next->prev = Curr;
        
        return Curr->val;

    }
    
    void put(int key, int value) {
        
        if(!hm[key]){
            Node *Curr = new Node(key , value);
            
            if(size == capacity){
                
                //Remove Last
                Node *temp = tail->prev;
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                hm.erase(temp->key);
            }else size++;
            
            
            //Add First
            Curr->prev = head;
            Curr->next = head->next;
            Curr->prev->next = Curr;
            Curr->next->prev = Curr;
            hm[key] = Curr;
        
        }else{
            //Update
            Node  *Curr = hm[key];
            
            
            //Remove At
            Curr->prev->next = Curr->next;
            Curr->next->prev = Curr->prev;
            
            
            //Add First
            Curr->prev = head;
            Curr->next = head->next;
            Curr->prev->next = Curr;
            Curr->next->prev = Curr;
            
            Curr->val = value;
            
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
