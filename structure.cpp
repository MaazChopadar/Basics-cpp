#include<iostream>
using namespace std;

typedef struct employee
     {
        int ID;
        char bestchar;
        float salary;

     }ep;

     union money
     {
            int rice;
            char car;
            float pounds;
     };
     
     
int main(){ 

    enum meal{breakfast , lunch , dinner};
    cout<<breakfast<<endl;
    cout<<lunch<<endl;
    cout<<dinner<<endl;

    ep maaz;
    ep shubam;
    ep kazi;

    union money m1;

    m1.rice = 34;
    cout<<m1.rice<<endl;

    maaz.ID =01;
    maaz.bestchar ='M';
    maaz.salary = 123456789;

    cout<<"the value is"<<maaz.ID<<endl;
    cout<<"the value is"<<maaz.bestchar<<endl;
    cout<<"the value is"<<maaz.salary<<endl;
     
    return 0;
}