#include<iostream>
using namespace std;

int main(){
    int marks[] = {23,34,45,65};
     int mathMarks[4];

    // mathMarks[0]=222;
    // mathMarks[1]=555;
    // mathMarks[2]=666;
    // mathMarks[3]=777;

    //  cout<<mathMarks[0]<<endl;
    // cout<<mathMarks[1]<<endl;
    // cout<<mathMarks[2]<<endl;
    // cout<<mathMarks[3]<<endl;


    // cout<<marks[0]<<endl;
    // cout<<marks[1]<<endl;
    // marks[2]=455;
    // cout<<marks[2]<<endl;
    // cout<<marks[3]<<endl;

    for (int i = 0; i <  4; i++)
    {
        // cout<<marks[i]<<endl;
        cout<<"the marks"<< i<<" is "<< marks[i]<<endl;
    }
    

    return 0;
}