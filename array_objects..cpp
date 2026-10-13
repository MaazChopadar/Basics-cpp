#include <iostream>
using namespace std;

class EMPLOYEE
{
    int id;
    int salary;

public:
    void setid()
    {
        cout << "enter the id of employee" << endl;
    }
} ;
int main()
{
    EMPLOYEE obj;
    obj.setid();

    return 0;
}