#include <bits/stdc++.h>
using namespace std;
void display(vector<int>a) {
  for (int i = 0; i < a.size(); i++)
  {
    cout << a[i] << endl;
  }
}
vector<int> solve(vector<int>arr)
{
   stack<int> stk;
    vector<int> nge(arr.size(),-1);
    for(int i = 0;i<arr.size();i++){
        
        while(stk.size() > 0 && arr[stk.top()] <= arr[i]){
            
            stk.pop();
          
        }
        
        if(stk.size() > 0){
           nge[i] = i - stk.top();
        }
        
       else if(stk.size() == 0){
            nge[i] = i + 1;
        }
        stk.push(i);
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
  vector<int>span(n, 0);
  span = solve(arr);
  display(span);
  return 0;
}
