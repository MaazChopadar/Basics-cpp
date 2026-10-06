#include<iostream>
using namespace std;
int c=65;
int main()
{
    int a,b,c;
    cout<<"enter a: \n";
    cin>>a;
    cout<<"enter b: \n";
    cin>>b;
    c=a+b;
    cout<<endl;
    cout<<"the sum of a and b is : \n"<<c<<endl;
    cout<<"the value c in global variable is: \n"<<::c;
    
    return 0;
}
