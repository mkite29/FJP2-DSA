/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(head == NULL)return head;
        
        unordered_map<Node*,Node*> hm;
        
        Node *copyHead = new Node(-1);
        Node *tail = copyHead;
        
        //phle Create ker lengei like Singly Linked List
        Node *original = head;
        while(original != NULL){
            Node *duplicate = new Node(original->val);
            tail->next = duplicate;
            tail = tail->next;
            
            hm[original] = duplicate;
            original = original->next;
        }
        
        //Updating the Random Pointers Now
        
        original = head;
        
        while(original != NULL){
            Node *randomNode = original->random;
            
            if(randomNode != NULL){
                randomNode = hm[randomNode];
            }
            
            hm[original]->random = randomNode;
            original = original->next;
        }
        
        tail->next = NULL;
        
        return copyHead->next;
        
    }
};
/////////////////////////////////////////////////////////////////////////////////////
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

//In O(1) Space with the approach i did on Unacademy by Deepak Gaur
//Link or Unlink the connections between the nodes approach

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)return head;
        
        Node *original = head;
        
        //Insert Duplicate Nodes in between the original nodes
        
        while(original != NULL){
            Node *duplicate = new Node(original->val);
            duplicate->next = original->next;
            
            original->next = duplicate;
            original = duplicate->next;
        }
        
        original = head;
        
        //Duplicate's Random Node ko Update kiya 
        while(original != NULL){
            Node *randomNode = original->random;
            if(original->random != NULL)
                randomNode = randomNode->next;
            
                original->next->random = randomNode;
                original = original->next->next;
            
        }
        
        original = head;
        Node *copyHead = head->next;
        
        while(original != NULL){
            Node *duplicate = original->next;
            original->next = original->next->next;
            
            if(duplicate->next != NULL){
                duplicate->next = duplicate->next->next;
            }
            
            original = original->next;
        }
        
        return copyHead;
        
    }
};
