#include <iostream>
using namespace std;

class EMPLOYEE
{
    int id;
    int salary;

public:
    void setid()
    {
        salary = 122;
        cout << "enter the id of employee" << endl;
        cin>>id;
    }

    void displayid(){
        cout<<"the id of this employee is"<<id<<endl;
    }
};
int main()
{
    //EMPLOYEE maaz, afshan, irfan, ateeb;
    //maaz.setid();
    //maaz.displayid();
    EMPLOYEE fb[4];
    for(int i=0; i<4;i++){
        fb[i].setid();
        fb[i].displayid();
    }

    return 0;
}