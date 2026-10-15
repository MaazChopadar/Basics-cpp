#include<iostream>
using namespace std;
class c2;
class c1{
    int val1;
    friend void exchange(c1 & , c2 &);
    public:
    void  indata(int a){
        val1 = a;
    }
    
    void display(void){
        cout<<val1<<endl;
    }
};

class c2{
    int val2;
    friend void exchange(c1 & , c2 &);
    public:
    void  indata(int b){
        val2 = b;
    }

    void display(void){
        cout<<val2<<endl;
    }
};

void exchange(c1 &x , c2 &y){
    int temp = x.val1;
    x.val1 = y.val2;
    y.val2 = temp;
}

int main(){
    c1 Oc1;
    c2 Oc2;

    Oc1.indata(34);
    Oc2.indata(55);
    exchange(Oc1 , Oc2);

    cout<<"the value of c1 after exchanging becomes:";
    Oc1.display();
    cout<<"the value of c1 after exchanging becomes:";
    Oc2.display();
    return 0;
}