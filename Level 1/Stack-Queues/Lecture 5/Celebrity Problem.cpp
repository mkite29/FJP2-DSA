https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1/
    int pop(stack<int> &s){
	int x = s.top();
	s.pop();

	return x;
}

int celeb(vector<vector<int>> &grid){


	int r = grid.size();

	stack<int> st;
	for(int i = 0;i<r;i++)
		st.push(i);
	
	
	while(st.size() > 1){
		

		//pop the first two elements
		int y = pop(st);
		int x = pop(st);
		
		//if x cant be a celeb
		if(grid[x][y] == 1)
			st.push(y);
	
		else{
			st.push(x);
		}
	}


	int x = pop(st);
	
	//it's row should be zero
	for(int i = 0;i<grid.size();i++){
		if(i == x)continue;
		if(grid[x][i] == 1)return -1;
	}

	// //it's row should be zero
	for(int i = 0;i<grid.size();i++){
		if(i == x)continue;
		if(grid[i][x] == 0)return -1;
	}

	//cout<<x<<endl;
	return x;
}
  
