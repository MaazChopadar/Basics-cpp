#include <iostream>
using namespace std;
int sum(int a, int b)
{

    int c = a + b;
    return c;
}
 //this will not swap a and b
void swap(int a, int b) 
{
    int temp = a;   
    a = b;
    b = temp;
}
//call by reference using pointers
void swappointer(int* a, int* b) 
{
    int temp = *a;   
    *a = *b;
    *b = temp;
}
// call by reference using c++ reference variables;
void swapreferencevar(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int x = 4, y = 5;
    cout << "the sum of 4 and 5 is\n" << sum(x, y);
    cout<<"the value of x is"<<x<<"and the value of y is"<<y<<endl;
    //swappointer(&x,&y); this will swap a and b using pointer reference
    swapreferencevar(x,y); //this will swap a and b using reference variables
        cout << "the value of x is"<<x<<"and the value of y is "<<y<<endl;

    return 0;
}