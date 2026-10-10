#include<iostream>
using namespace std;
int factorial(int n){
    if(n<=1){
        return 1;
    }
    else{
    return n*factorial(n-1);
    }
}
int main(){
    int n;
    cout<<"enter the number"<<endl;
    cin>>n;
  cout<<factorial(5);  
    return 0;
}