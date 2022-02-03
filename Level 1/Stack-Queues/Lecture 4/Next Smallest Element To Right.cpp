#include <bits/stdc++.h>
using namespace std;
void display(vector<int>a) {
  for (int i = 0; i < a.size(); i++)
  {
    cout << a[i] << " ";
  }
}
vector<int> solve(vector<int>arr)
{
  vector<int> nge(arr.size(),-1);
  stack<int> st;
  
  for(int i = arr.size()-1;i>=0;i--){
      
      while(!st.empty() and arr[i] <= arr[st.top()]){
          st.pop();
      }
      
      if(st.size() > 0){
          nge[i] =  arr[st.top()];
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
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  vector<int>nge(n, 0);
  nge = solve(arr);
  display(nge);
  return 0;
}
