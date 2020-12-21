#include <iostream>
using namespace std;

int main()
{
    cout << "Enter Number: ";
    int number;
    cin >> number;

    if (number >= 1)
    {
        for (int i = 0; i < number; i++)
        {
            for (int j = 0; j < number; j++)
            {
                cout << "*";
            }
            cout << endl;
        }
    }
}