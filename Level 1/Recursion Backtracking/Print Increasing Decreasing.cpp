#include<iostream>
using namespace std;

void printIncDec(int n){
    // write your code here

    if(n == 0){
        //cout<<n<<endl;
        return;
    }    
    cout<<n<<endl;
    printIncDec(n-1);
    cout<<n<<endl;
}


int main(){
    int n; cin>>n;
    printIncDec(n);
}
