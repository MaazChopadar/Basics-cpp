
#include <iostream>
using namespace std;

class Student
{
private:
    // Data members / Attributes
    int marks1;
    int marks2;

public:
    // Member function
    void setMarks(int m1, int m2)
    {
        marks1 = m1;
        marks2 = m2;
    }

    // Friend function declaration
    friend void calculateTotal(Student s);
};

// Friend function definition
void calculateTotal(Student s)
{
    int total = s.marks1 + s.marks2;

    cout << "Marks 1: " << s.marks1 << endl;
    cout << "Marks 2: " << s.marks2 << endl;
    cout << "Total Marks: " << total << endl;
}

int main()
{
    // Creating an object
    Student s1;

    // Calling the member function
    s1.setMarks(85, 90);

    // Calling the friend function
    calculateTotal(s1);

    return 0;
}
