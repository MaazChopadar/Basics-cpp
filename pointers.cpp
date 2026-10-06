#include<iostream>
using namespace std;

int main(){
    int a=10;
    int*b =&a;

    cout<<"The address of a is:"<<b<<endl;
    cout<<"The address of a is:"<<&a<<endl;

    cout<<"The value at address of b is:"<<*(&a)<<endl;
    cout<<"The value at address of b is:"<<*b<<endl;

    int** c =&b;
    cout<<"The address of b is:"<<&b<<endl;
    cout<<"The address of b is:"<<c<<endl;

    cout<<"The value at address of c is:"<<*c<<endl;
    cout<<"The value at address of c is:"<<**(&b)<<endl;

    return 0;
}