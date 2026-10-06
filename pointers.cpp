#include<iostream>
using namespace std;

int main(){
    int a=10;
    int*b =&a;

    cout<<"The adress of a is:"<<b<<endl;
    cout<<"The adress of a is:"<<&a<<endl;

    cout<<"The value at adress of b is:"<<*(&a)<<endl;
    cout<<"The value at adress of b is:"<<*b<<endl;

    int** c =&b;
    cout<<"The adress of b is:"<<&b<<endl;
    cout<<"The adress of b is:"<<c<<endl;

    cout<<"The value at adress of c is:"<<*c<<endl;
    cout<<"The value at adress of c is:"<<**(&b)<<endl;

    return 0;
}