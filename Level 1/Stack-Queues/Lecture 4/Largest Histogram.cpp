#include <bits/stdc++.h>
using namespace std;

void display(vector<int>a) {
  for (int i = 0; i < a.size(); i++)
    cout << a[i] << "   ";
  
}


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
  vector<int> nge(arr.size(),-1);
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

int main(int argc, char** argv)
{
  int n;
  cin >> n;

  vector<int>arr(n, 0);
  for (int i = 0; i < n; i++){
    cin >> arr[i];
  }

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

  cout<<ans<<endl;
  
  return 0;
}
