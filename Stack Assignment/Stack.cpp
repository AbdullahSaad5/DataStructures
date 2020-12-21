#include <iostream>
using namespace std;

const int length = 10;
int array[length];
int Index = -1;

void push(int value)
{
    if (Index >= 10)
    {
        cout << "\nStack is full" << endl;
    }
    else
    {
        Index++;
        array[Index] = value;
    }
}

void pop()
{
    if (Index == -1)
    {
        cout << "\nStack is empty" << endl;
    }
    else
    {
        cout << "\nValue Popped: " << array[Index] << endl;
        array[Index] = 0;
        Index--;
    }
}

int main()
{
    bool infinite_loop = true;
    while (infinite_loop)
    {
        cout << "\nStack Methods\n"
                "1. Add Value\n"
                "2. Pop Value\n"
                "3. Exit\n"
                "Choice: ";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            int value;
            cout << "\nEnter value: ";
            cin >> value;
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            infinite_loop = false;
            break;
        }
    }
}