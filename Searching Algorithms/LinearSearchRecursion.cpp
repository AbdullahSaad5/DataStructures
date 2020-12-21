#include <iostream>
using namespace std;

int length;

void findValue(int value, int array[], int index)
{
    if (value == array[index])
    {
        cout << "Value Found at Index " << index << endl;
    }
    else if (index == length - 1)
    {
        cout << "Value Not Found" << endl;
    }
    else
    {
        findValue(value, array, ++index);
    }
}

int main()
{
    int array[10];
    length = 10;
    for (int i = 0; i < 10; i++)
    {
        array[i] = i * 2;
    }

    int value;
    cout << "Enter Number:";
    cin >> value;
    findValue(value, array, 0);
}