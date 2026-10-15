#include<iostream>
using namespace std;

class Complex{
      int a , b;
      
      public:
      void setnumber(int n1, int n2){
        a = n1;
        b = n2;
      }

      void printnumber(){
        cout<<"your number is"<<a<<" + "<<b<<"i"<<endl;
      }
    };
int main(){
    
    return 0;
}