void display2(Node *root){

		
		cout<<"Node Pre "<<root->data<<endl;
		for(auto &i: root->children){
			
			cout<<"Edge Pre "<<root->data<<"--"<<i->data<<endl;
			display2(i);
			cout<<"Edge Post "<<root->data<<"--"<<i->data<<endl;
			
		}
		cout<<"Node Post "<<root->data<<endl;
	}
