#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int>&arr,int idx,int data,vector<int>&ans){

    if(idx == arr.size()){
        return;
    }

    if(arr[idx] == data){
        ans.push_back(idx);
    }

    solve(arr,idx+1,data,ans);
}
vector<int> allIndex(vector<int>& arr, int idx, int data, int count)
{   
    vector<int> ans;

    solve(arr,idx,data,ans);

    return ans;
}

int main() {
  int n ;
  cin >> n;
  vector<int> arr;
  for (int i = 0; i < n; i++) {
    int d;
    cin >> d;
    arr.push_back(d);
  }
  int data;
  cin >> data;
  vector<int> ans = allIndex(arr, 0, data, 0);
  if (ans.size() == 0) {
    cout << endl;
    return 0;
  }
  for (int ele : ans) cout << ele << endl;

  return 0;
}
