
#include <iostream>
using namespace std;

int main()
{
    // Upper half
    for (int i = 0; i <= 4; i++)
    {
        for (int j = 0; j < 4 - i; j++)
        {
            cout << "  ";
        }

        for (int j = 0; j < (2 * i) + 1; j++)
        {
            cout << "* ";
        }

        cout << endl;
    }

    // Lower half
    for (int i = 3; i >= 0; i--)
    {
        for (int j = 0; j < 4 - i; j++)
        {
            cout << "  ";
        }

        for (int j = 0; j < (2 * i) + 1; j++)
        {
            cout << "* ";
        }

        cout << endl;
    }

    return 0;
}
