#include <iostream>
using namespace std;

int Index = -1;
bool error = false;
int length = 0;

void push(char value, char array[])
{
    if (Index == length - 1)
    {
        cout << "\nStack is full" << endl;
    }
    else
    {
        Index++;
        array[Index] = value;
    }
}

char pop(char array[])
{
    if (Index == -1)
    {
        cout << "\nStack is empty" << endl;
        error = true;
        return NULL;
    }
    else
    {
        cout << "\nValue Popped: " << array[Index] << endl;
        char value = array[Index];
        Index--;
        return value;
    }
}

int main()
{
    cout << "Enter Equation: ";
    string equation;
    cin >> equation;

    length = equation.size();
    char array[length];

    for (int i = 0; i < length; i++)
    {
        if (equation[i] == '(')
        {
            push(equation[i], array);
        }
        else if (equation[i] == ')')
        {
            pop(array);
        }
        else
        {
            continue;
        }
    }

    if (Index == -1 && !error)
    {
        cout << "Equation is balanced" << endl;
    }
    else
    {
        cout << "Equation is not balanced" << endl;
    }
}