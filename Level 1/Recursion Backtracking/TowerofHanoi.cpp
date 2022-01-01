#include <bits/stdc++.h>
using namespace std;


void toi(int n , int A , int B , int C){

	if(n == 0){
		return;
	}

	toi(n-1,A , C , B);
	cout<<n <<"[" << A << "->" << B <<"]"<<endl;
	toi(n-1,C , B , A);
}
int main(){

	int n;
	cin>>n;

	toi(n,1,2,3);




	return 0;
}
