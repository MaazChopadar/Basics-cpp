#include<iostream>
using namespace std;

int main(){
    //pointers and arrays

    int marks[] = {45,56,67,78};

    int* p = marks;

    cout<<"the value of marks[0] is"<<*p<<endl;
    cout<<"the value of marks[0] is"<<*(p+1)<<endl;
    cout<<"the value of marks[0] is"<<*(p+2)<<endl;
    cout<<"the value of marks[0] is"<<*(p+3)<<endl;


    return 0;
}