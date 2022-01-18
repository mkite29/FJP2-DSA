#include <bits/stdc++.h>
using namespace std;


class Node{
public:
	int data;
	Node *next;
};

class LinkedList{
private:
	Node *head = NULL;
	Node *tail = NULL;
	int size = 0;

public:
	void display(){
		Node *Curr = head;
		while(Curr != NULL){
			cout<<Curr->data<<" ";
			Curr = Curr->next;
		}
	}

	void addAtHead(int val){
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


	void addAtTail(int val){
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

		size++;
		if(index == 0){
			addAtHead(val);
			return;
		}

		if(index == size){
			addAtTail(val);
			return;
		}

		Node *makeNode = new Node();
		makeNode->data = val;
		makeNode->next = NULL;

		Node *Curr = head;
    	int i = 0;

    	while(Curr != NULL){

    		if(i == index-1){
    			break;
    		}
    		i++;
    		Curr = Curr->next;
    	}


    	makeNode->next = Curr->next;
    	Curr->next = makeNode;

    }

    void deleteAtIndex(int index) {
    	size--;

		if(index == 0){
			Node *Curr = head;
			head = head->next;
			delete(Curr);
			return;
		}


		
		Node *Curr = head;
    	int i = 0;

    	while(Curr != NULL){

    		if(i == index-1){
    			break;
    		}
    		i++;
    		Curr = Curr->next;
    	}

    	Node *real = Curr->next;
    	Curr->next = real->next;

    	delete(real);

    	//ek edge case hai ager last node ko delete
    	//kiya to curr ko tail bhi bana do .
    	if(index == size - 1){
    		tail = Curr;
    	}


    }

	int get(int idx){
		int i = 0;
		Node *Curr = head;
		while(Curr != NULL){

			if(i == idx){
				return Curr->data;
			}
			i++;
			Curr = Curr->next;
		}

		return -1;
	}

	int getsize(){
		return size;
	}


};

int main(){

	LinkedList obj;

	obj.addAtTail(10);
	obj.addAtTail(20);
	obj.addAtTail(30);
	obj.addAtTail(40);
	obj.addAtTail(50);
	
	// obj.addAtIndex(2,29);
	// obj.addAtIndex(3,39);
	// obj.addAtIndex(4,49);



	//obj.deleteAtIndex(5);
	obj.display();
	cout<<endl;
	obj.addAtHead(0);
	obj.display();
	cout<<endl;

	obj.addAtIndex(1,100);
	obj.display();
	cout<<endl;
	//cout<<obj.get(1);




	return 0;
}