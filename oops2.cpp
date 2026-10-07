#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    int personID;
    string name;

public:
    Person(int id, string n)
    {
        personID = id;
        name = n;
    }
};

class Customer : public Person
{
private:
    string email;
    string address;

public:
    Customer(int id, string n, string e, string a)
        : Person(id, n)
    {
        email = e;
        address = a;
    }

    void displayCustomer()
    {
        cout << "Customer ID: " << personID << endl;
        cout << "Name: " << name << endl;
        cout << "Email: " << email << endl;
        cout << "Address: " << address << endl;
    }
};

int main()
{
    Customer c1(
        1,
        "Mohammed",
        "maaz@gmail.com",
        "Bengaluru"
    );

    c1.displayCustomer();

    return 0;
}