void display(Node *root){
		if(root == NULL)return;

		cout<<root->data<<"-> ";
		for(auto &i : root->children){
			cout<<i->data<<", ";
		}		
		cout<<".";
		cout<<endl;

		for(auto &i: root->children){
			display(i);
		}
	}
