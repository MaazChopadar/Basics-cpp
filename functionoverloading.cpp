#include<iostream>
using namespace std;
int sum(int a, int b){
    cout<<"function with 2 arguments "<<endl;
    return a+b;
}

int sum(int a , int b , int c){
    cout<<"function with 3 arguments "<<endl;
    return a+b+c;
}
int main(){
    cout<<"the sum of 6 and 7 is "<<sum(6,7)<<endl;
    cout<<"the sum of 3,6 and 7 is "<<sum(3,6,7)<<endl;
    
    return 0;
}