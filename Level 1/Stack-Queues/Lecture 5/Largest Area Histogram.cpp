class Solution {
public:
    vector<int> nsel(vector<int>arr)
{
 vector<int> nge(arr.size(),-1);
  stack<int> st;
  
  for(int i = 0;i<arr.size();i++){
    
    while(!st.empty() and arr[i] <= arr[st.top()]){
      st.pop();
    }      

    if(st.size() > 0)
      nge[i] = st.top();

    st.push(i);

    
  }
  
  return nge;
  
}

vector<int> nser(vector<int>arr)
{
  vector<int> nge(arr.size(),arr.size());
  stack<int> st;
  
  for(int i = arr.size()-1;i>=0;i--){
      
      while(!st.empty() and arr[i] <= arr[st.top()]){
          st.pop();
      }
      
      if(st.size() > 0){
          nge[i] =  st.top();
      }
      
      st.push(i);
    
  }
  
  return nge;
  
}
    
    int largestRectangleArea(vector<int>& arr) {
        
        int n = arr.size();
        vector<int>arr1(n, 0);
        arr1 = nsel(arr);
        
        vector<int>arr2(n, 0);
        arr2 = nser(arr);
        
        int ans = INT_MIN;

  for(int i = 0;i<n;i++){

    if(arr1[i] == -1 and arr2[i] == -1){
      ans = max(ans,arr[i] * n);
    }
    else{
      ans = max(ans,arr[i] * (arr2[i] - arr1[i] - 1));
    }

  }
        return ans;
    }
};
