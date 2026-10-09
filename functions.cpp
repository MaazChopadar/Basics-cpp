#include<iostream>
using namespace std;

int sum(int ,int);

void g();

int main(){
    int num1 , num2;
    cout<<"Enter the first number:"<<endl;
    cin>>num1;
    cout<<"Enter the second number:"<<endl;
    cin>>num2;
    cout<<"the sum is "<<sum(num1,num2);
    g();
    return 0;


}int sum(int a , int b){
   int c= a+b;
   return c;
}
void g(){

    cout<<"\n Hello GM";
}