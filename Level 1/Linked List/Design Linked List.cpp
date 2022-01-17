class Node{
public:
	int data;
	Node *next;
};


class MyLinkedList {
    Node *head;
    Node *tail;
    int size;
public:
    MyLinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    
    int get(int index) {
        
        
        int i = 0;
		Node *Curr = head;
		while(Curr != NULL){

			if(i == index){
				return Curr->data;
			}
			i++;
			Curr = Curr->next;
		}

        return -1;
    }
    
    void addAtHead(int val) {
        Node *makeNode = new Node();
		makeNode->data = val;
		makeNode->next = NULL;
		size++;

		if(head == NULL){
			head = makeNode;
            tail = makeNode;
			return;
		}

		makeNode->next = head;
		head  = makeNode;

    }
    
    void addAtTail(int val) {
        Node *makeNode = new Node();
		makeNode->data = val;
		makeNode->next = NULL;
		size++;

		if(head == NULL){
			head = makeNode;
			tail = makeNode;	
			return;
		}

		tail->next = makeNode;
		tail = makeNode;
    }
    
    void addAtIndex(int index, int val) {
        
        if(index < 0 || index > size)return;
        
        
		if(index == 0){
			addAtHead(val);
			return;
		}

		else if(index == size){
			addAtTail(val);
			return;
		}
        
        size++;
		Node *makeNode = new Node();
		makeNode->data = val;
		makeNode->next = NULL;

		Node *Curr = head;
    	int i = 0;

    	while(Curr != NULL){
    		if(i == index-1)
    			break;
    		
    		i++;
    		Curr = Curr->next;
    	}

    	makeNode->next = Curr->next;
    	Curr->next = makeNode;
    }
    
    void deleteAtIndex(int index) {
        
        if(head == NULL)return;
        if(index < 0 || index >= size)return;
        
       
        
        if(index == 0 and head !=NULL){
            
			Node *Curr = head;
			head = head->next;
			delete(Curr);
            
            if(size == 1){
                tail = NULL;
            }
            size--;
			return;
		}
        
       
        else
        {
            
            Node *Curr2 = head;
    	    int i = 0;

    	    while(Curr2 != NULL){

    		if(i == index-1)
    			break;

    	        i++;
            
    		    Curr2 = Curr2->next;
    	    }

    	    Node *real = Curr2->next;
    	    Curr2->next = real->next;
    	    delete(real);
            
            if(index == size-1){
                tail = Curr2;
            }
            size--;
        }
             
        
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
