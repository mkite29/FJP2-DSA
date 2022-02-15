Node *construct(vector<int> &arr){
		
		Node *root = new Node();
		stack<Node*> stk;

		for(int i = 0;i<arr.size();i++){

			if(arr[i] == -1)
				stk.pop();
			
			else{
				Node *curr = new Node(arr[i]);

				if(stk.size() > 0)
					stk.top()->children.push_back(curr);
				else
					root = curr;
				

				stk.push(curr);
			}

		}

		return root;
	}
